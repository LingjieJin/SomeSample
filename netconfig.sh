#!/bin/sh

/sbin/ifconfig lo 127.0.0.1

MAC=$(fw_printenv -n ethaddr)

if [ -n "$MAC" -a "$MAC" != "10:20:30:40:50:60" ]; then
    cur_mac=$(cat /sys/class/net/eth0/address)
    if [ "$MAC" != "$cur_mac" ]; then
        /sbin/ifconfig eth0 hw ether $MAC
    fi
fi