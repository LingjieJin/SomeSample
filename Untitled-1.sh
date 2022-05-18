#!/bin/sh

export PATH=/bin:/sbin:/usr/bin:/app/bin:/app/abin
export LD_LIBRARY_PATH=/lib:/usr/lib:/app/lib

APP_DIR=/app
SYS_INIT=sys_init.sh
APP_INIT=app_init.sh
APP_START=start.sh

if [ -x /usr/bin/chk_ver.sh ]; then
        /usr/bin/chk_ver.sh
fi

if [ -x $APP_DIR/patch.sh ]; then
        $APP_DIR/patch.sh
fi

if [ -f $APP_DIR/$SYS_INIT ] && [ -x $APP_DIR/$SYS_INIT ]; then
        cd $APP_DIR
        ./$SYS_INIT
fi

if [ -f $APP_DIR/$APP_INIT ] && [ -x $APP_DIR/$APP_INIT ]; then
        cd $APP_DIR
        ./$APP_INIT
fi

if [ -f $APP_DIR/$APP_START ] && [ -x $APP_DIR/$APP_START ]; then
        cd $APP_DIR
        ./$APP_START
fi

if [ -x /usr/bin/noodles ] ; then
        /usr/bin/noodles &
fi

if [ ! -d /app/abin ] ; then
        echo "app fail"

        /usr/bin/sd_hotplug.sh
        if [ -d /mnt/sd/upgrade ] ; then
                if [ -f /usr/bin/iu.sh ] ; then
                        cp /usr/bin/iu.sh /home/
                        chmod +x /home/iu.sh
                fi
                if [ -f /mnt/sd/iu.sh ] ; then
                        cp /mnt/sd/iu.sh /home/
                        chmod +x /home/iu.sh
                fi
                if [ -x /home/iu.sh ] ; then
                        /home/iu.sh -p -d -s
                fi
        fi
fi