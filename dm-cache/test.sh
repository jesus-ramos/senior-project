#!/bin/bash

SRC="/dev/sdd"
CACHE="/dev/sdc"
DM_CACHE="dm-cache.ko"

insmod $DM_CACHE
echo 0 16777216 cache $SRC $CACHE 0 8 2097152 1 0 node1 | dmsetup create cache
mount /dev/mapper/cache /mnt/test_mnt
