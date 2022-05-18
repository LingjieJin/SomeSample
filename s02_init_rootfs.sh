#!/bin/sh

ulimit -s 1024

export PATH=/bin:/sbin:/usr/bin:/app/bin:/app/abin
export LD_LIBRARY_PATH=/lib:/usr/lib:/app/lib

echo "init_rootfs begin"

APP_DIR=/app
data_mtd_no=$(awk -F: '/\"data\"/{print substr($1, 4)}' /proc/mtd)
res_mtd_no=$(awk -F: '/\"res\"/{print substr($1, 4)}' /proc/mtd)

bootid=$(fw_printenv -n bootid)
if [ "$bootid" != "" ] ; then
    echo "bootid=${bootid}"
fi

if [ "$bootid" = "1" ] ; then
    app_mtd_no=$(awk -F: '/\"app1\"/{print substr($1, 4)}' /proc/mtd)
    if [ "$app_mtd_no" = "" ] ; then
        app_mtd_no=$(awk -F: '/\"app\"/{print substr($1, 4)}' /proc/mtd)
    fi
else
    app_mtd_no=$(awk -F: '/\"app\"/{print substr($1, 4)}' /proc/mtd)
fi

check_up=$(myinfo.sh check_up)
if [ "$check_up" != "OK" ] ; then
        echo "Warning: check upgrade fail!!!"
fi

target=$(myinfo.sh target)
echo "target=${target}"

#default APP FS
if [ "$target" = "debug" ] ; then
    app_fs=jffs2
else
    app_fs=cramfs
fi

if [ -x /usr/bin/f_cp ] ; then
    app_ckfs=$(/usr/bin/ckfs /dev/mtdblock${app_mtd_no})
    if [ "${app_ckfs}" = "jffs2" ] || [ "${app_ckfs}" = "cramfs" ] || [ "${app_ckfs}" = "squashfs" ] ; then
        app_fs=${app_ckfs}
    elif [ "${app_ckfs}" = "none" ] ; then
        app_fs=jffs2
    else
        echo "unknown app_fs_name:${app_ckfs}"
    fi
fi

echo "/bin/mount -t ${app_fs} /dev/mtdblock${app_mtd_no} $APP_DIR"
/bin/mount -t ${app_fs} /dev/mtdblock${app_mtd_no} $APP_DIR

echo "/bin/mount -t jffs2 /dev/mtdblock${data_mtd_no} $APP_DIR/userdata"
/bin/mount -t jffs2 /dev/mtdblock${data_mtd_no} $APP_DIR/userdata
if [ "${res_mtd_no}" != "" ] ; then
    echo "/bin/mount -t jffs2 /dev/mtdblock${res_mtd_no} $APP_DIR/res"
    /bin/mount -t jffs2 /dev/mtdblock${res_mtd_no} $APP_DIR/res
fi

echo "init_rootfs OK"