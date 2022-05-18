#!/bin/sh

version=4.1

if [ "$1" = "--version" ] ; then
        echo $version
        exit 0
fi

if [ "${app_root_dir}" = "" ] ; then
        app_root_dir=/app
fi

if [ "$1" = "" ] ; then
        echo "Usage: $0 kernel_ver: get kernel version"
        echo "       $0 sdk_ver: get sdk version"
        echo "       $0 wifi: get wifi"
        echo "       $0 sensor: get sensor"
        echo "       $0 sensor_width: get sensor_width"
        echo "       $0 sensor_height: get sensor_height"
        echo "       $0 soc: get soc"
        echo "       $0 org_mac: original eth0 mac (factory default)"
        echo "       $0 def_mac: default eth0 mac (defined in uboot env)"
        echo "       $0 cur_mac: current eth0 mac"
        echo "       $0 sn: serial number"
        echo "       $0 eth0_ip: eth0 current ip"
        echo "       $0 def_ip: eth0 default ip"
        echo "       $0 magic: get image magic number (hex)"
        echo "       $0 product_no: get product number (hex)"
        echo "       $0 img_ver: version number (dec)"
        echo "       $0 brand: product brand"
        echo "       $0 model: model name"
        echo "       $0 hw_id: hardware id"
        echo "       $0 hw_name: hardware name"
        echo "       $0 board_id: board id"
        echo "       $0 def_hw_name: default hardware name"
        echo "       $0 dev_type: device type"
        echo "       $0 fw_ver: get current firmware version"
        echo "       $0 build_date: get current firmware build date"
        echo "       $0 img_fw_ver: get image original firmware version"
        echo "       $0 target: image taget, release|debug|upgrade|..."
        echo "       $0 http_port: get http port"
        echo "       $0 https_port: get https port"
        echo "       $0 rtsp_port: get rtsp port"
        echo "       $0 onvif_port: get ONVIF port"
        echo "       $0 check_up: check upgrade OK/FAIL"
        echo "       $0 <image name> size: get image size (dec)"
        echo "       $0 <image name> address (dec): get image address"
        echo "       $0 <image name> crc (hex): get image crc"
        echo "          image name: uboot | kernel | rootfs | app"
fi

flash_tool=mtdt
if [ -f /usr/bin/$flash_tool ] ; then
        local_flash_tool=/usr/bin/$flash_tool
elif [ -f ${app_root_dir}/bin/$flash_tool ] ; then
        local_flash_tool=${app_root_dir}/bin/$flash_tool
else
        echo "not found $flash_tool"
        exit 255
fi

imginfo_tool=imginfo
if [ -f /usr/bin/$imginfo_tool ] ; then
        local_imginfo_tool=/usr/bin/$imginfo_tool
elif [ -f ${app_root_dir}/bin/$flash_tool ] ; then
        local_imginfo_tool=${app_root_dir}/bin/$imginfo_tool
else
        echo "not found $imginfo_tool"
        exit 255
fi

if [ "$1" = "kernel_ver" ] ; then
        echo "$(awk '{print $3}' /proc/version)"
        exit 0
elif [ "$1" = "sdk_ver" ] ; then
        if [ -f ${app_root_dir}/sysinfo/sdk_ver ] ; then
                echo "$(cat ${app_root_dir}/sysinfo/sdk_ver)"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "fw_ver" ] ; then
        si_fw_ver=$(fw_printenv -n fw_ver)
        if [ "${si_fw_ver}" != "" ] ; then
                echo "${si_fw_ver}"
        elif [ -f ${app_root_dir}/sysinfo/fw_ver ] ; then
                si_fw_ver=$(awk -F= '/^fw_ver=/{print $2}' ${app_root_dir}/sysinfo/fw_ver)
                if [ "${si_fw_ver}" = "" ] ; then
                        si_fw_ver=$(cat ${app_root_dir}/sysinfo/fw_ver)
                fi
                echo "${si_fw_ver}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "build_date" ] ; then
        if [ -f ${app_root_dir}/sysinfo/fw_ver ] ; then
                si_fw_build_date=$(awk -F= '/^fw_build_date=/{print $2}' ${app_root_dir}/sysinfo/fw_ver)
                echo "${si_fw_build_date}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "def_hw_name" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_name ] ; then
                echo "$(cat ${app_root_dir}/sysinfo/hw_name)"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "hw_name" ] ; then
        if [ -f ${app_root_dir}/userdata/hw_name ] ; then
                echo "$(cat ${app_root_dir}/userdata/hw_name)"
        elif [ -f ${app_root_dir}/sysinfo/hw_name ] ; then
                echo "$(cat ${app_root_dir}/sysinfo/hw_name)"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "board_id" ] ; then
        if [ -f ${app_root_dir}/sysinfo/board_id ] ; then
                echo "$(cat ${app_root_dir}/sysinfo/board_id)"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "dev_type" ] ; then
        if [ -f ${app_root_dir}/sysinfo/dev_type ] ; then
                echo "$(cat ${app_root_dir}/sysinfo/dev_type)"
        else
                echo ""
        fi
        exit 0
elif [ "$1" = "wifi" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_info ] ; then
                hw_wifi=$(awk -F= '/^wifi=/{print $2}' ${app_root_dir}/sysinfo/hw_info | awk -F@ '{print $1}')
                if [ "${hw_wifi}" = "no" ] || [ "${hw_wifi}" = "" ] ; then
                        echo "none"
                else
                        echo "${hw_wifi}"
                fi
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "sensor" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_info ] ; then
                hw_sensor=$(awk -F= '/^sensor=/{print $2}' ${app_root_dir}/sysinfo/hw_info | awk -F@ '{print $1}')
                echo "${hw_sensor}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "sensor_width" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_info ] ; then
                hw_sensor_width=$(awk -F= '/^sensor_width=/{print $2}' ${app_root_dir}/sysinfo/hw_info | awk -F@ '{print $1}')
                echo "${hw_sensor_width}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "sensor_height" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_info ] ; then
                hw_sensor_height=$(awk -F= '/^sensor_height=/{print $2}' ${app_root_dir}/sysinfo/hw_info | awk -F@ '{print $1}')
                echo "${hw_sensor_height}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "soc" ] ; then
        if [ -f ${app_root_dir}/sysinfo/hw_info ] ; then
                hw_soc=$(awk -F= '/^soc=/{print $2}' ${app_root_dir}/sysinfo/hw_info)
                echo "${hw_soc}"
        else
                echo "unknown"
        fi
        exit 0
elif [ "$1" = "org_mac" ] ; then
        echo "10:20:30:40:50:60"
        exit 0
elif [ "$1" = "def_mac" ] ; then
        echo "$(fw_printenv -n ethaddr)"
        exit 0
elif [ "$1" = "cur_mac" ] ; then
        echo "$(cat /sys/class/net/eth0/address)"
        exit 0
elif [ "$1" = "sn" ] ; then
        echo "$(fw_printenv -n serial#)"
        exit 0
elif [ "$1" = "eth0_ip" ] ; then
        echo `ifconfig eth0 | grep "inet addr" | awk -F: '{print $2}' | awk '{print $1}'`
        exit 0
elif [ "$1" = "def_ip" ] ; then
        echo "$(fw_printenv -n ipaddr)"
        exit 0
elif [ "$1" = "http_port" ] ; then
        http_port=80
        if [ -f ${app_root_dir}/userdata/ipc.db ] ; then
                if [ -x ${app_root_dir}/bin/db_util ] ; then
                        http_port=$(${app_root_dir}/bin/db_util -f ${app_root_dir}/userdata/ipc.db -g -n http_port -d 80)
                else
                        http_port=$(awk -F= '/^http_ports[0]=/{print $2}' ${app_root_dir}/userdata/ipc.db | head -n 1)
                fi
                if [ "$http_port" = "" ] ; then
                        http_port=80
                fi
        fi
        echo "$http_port"
        exit 0
elif [ "$1" = "https_port" ] ; then
        if [ -f ${app_root_dir}/userdata/ipc.db -a -x ${app_root_dir}/bin/db_util ] ; then
                echo "$(${app_root_dir}/bin/db_util -f ${app_root_dir}/userdata/ipc.db -g -n https_port -d 443)"
        else
                echo "443"
        fi
        exit 0
elif [ "$1" = "rtsp_port" ] ; then
        if [ -f ${app_root_dir}/userdata/ipc.db -a -x ${app_root_dir}/bin/db_util ] ; then
                echo "$(${app_root_dir}/bin/db_util -f ${app_root_dir}/userdata/ipc.db -g -n rtsp_port -d 8554)"
        else
                echo "8554"
        fi
        exit 0
elif [ "$1" = "onvif_port" ] ; then
        if [ -f ${app_root_dir}/userdata/ipc.db -a -x ${app_root_dir}/bin/db_util ] ; then
                echo "$(${app_root_dir}/bin/db_util -f ${app_root_dir}/userdata/ipc.db -g -n onvif_port -d 6688)"
        else
                echo "6688"
        fi
        exit 0
elif [ "$1" = "prodid" ] ; then
        if [ -f ${app_root_dir}/userdata/prodid ] ; then
        echo "$(cat ${app_root_dir}/userdata/prodid)"
        fi
    exit 0
elif [ "$1" = "model" ] ; then
        if [ -d ${app_root_dir}/prodid ] ; then
        cur_prodid=$(cat ${app_root_dir}/userdata/prodid)
        if [ "${cur_prodid}" != "" ] &&  [ "${cur_prodid}" != "unknown" ] ; then
            cur_model=$(awk -F= '/^model=/{print $2}' ${app_root_dir}/prodid/${cur_prodid}/prod_info)
            if [ "${cur_model}" != "" ] ; then
                echo ${cur_model}
                exit 0
            fi
        fi
        fi
fi

tmp_file_n=/tmp/tmp_info_n.dump
tmp_file_o=/tmp/tmp_info_o.dump

if [ -f $tmp_file_n ] ; then 
        tmp_file=$tmp_file_n
elif [ -f $tmp_file_o ] ; then
        tmp_file=$tmp_file_o
fi

if [ "$tmp_file" = "" ] ; then
    bootid=$(fw_printenv -n bootid)
    block_size=65536
    if [ "$bootid" = "1" ] ; then
        kernel_mtd_no=$(awk -F: '/\"kernel1\"/{print substr($1, 4)}' /proc/mtd)
        if [ "$kernel_mtd_no" = "" ] ; then
            kernel_mtd_no=$(awk -F: '/\"kernel\"/{print substr($1, 4)}' /proc/mtd)
            block_size=131072
        fi
    else
        kernel_mtd_no=$(awk -F: '/\"kernel\"/{print substr($1, 4)}' /proc/mtd)
    fi
        kernel_size=$($local_flash_tool info /dev/mtd${kernel_mtd_no} | awk '/mtd.size/{print $3}')
        let backup_block_off=$kernel_size-$block_size

        $local_flash_tool read /dev/mtd${kernel_mtd_no} $backup_block_off 1024 $tmp_file_n > /dev/null
        magic_no=$($local_imginfo_tool $tmp_file_n magic)
        if [ "$magic_no" != "a4b7c9f8" ] && [ "$magic_no" != "5b483607" ]  && [ "$magic_no" != "2a4c4232" ]; then
                bootstrap_mtd_no=$(awk -F: '/\"bootstrap\"/{print substr($1, 4)}' /proc/mtd)
                $local_flash_tool read /dev/mtd${bootstrap_mtd_no} 0 1024 $tmp_file_o > /dev/null
                tmp_file=$tmp_file_o
                rm -f $tmp_file_n
        else
                tmp_file=$tmp_file_n
        fi
fi

if [ "$1" = "check_up" ] ; then
        if [ -f $tmp_file_n ] ; then 
                echo "OK"
        else
                echo "FAIL"
        fi
        exit 0
fi

if [ ! -f $tmp_file ] ; then
        echo "read info error"
        exit 1
fi

touch /home/imginfo_no_error
if [ "$1" = "img_fw_ver" ] ; then
        $local_imginfo_tool $tmp_file fw_ver
elif [ "$1" = "img_model" ] ; then
        $local_imginfo_tool $tmp_file model
else
        $local_imginfo_tool $tmp_file $@
fi
rm -f /home/imginfo_no_error