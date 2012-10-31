#!/bin/bash

SRC="/dev/sdd1"
CACHE="/dev/sdc"
DM_CACHE="dm-cache.ko"

insmod $DM_CACHE
echo 0 167719797 cache $SRC $CACHE 0 8 1048576 1 0 node1 | dmsetup create cache
mount /dev/mapper/cache /mnt/test_mnt
