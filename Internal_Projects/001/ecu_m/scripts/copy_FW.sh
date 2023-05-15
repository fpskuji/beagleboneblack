HOME_PATH="/home/gaviolam"
BASEPATH="${HOME_PATH}/linux_kernel_src/dunfell/poky/build"
IMAGEPATH="${BASEPATH}/tmp/deploy/images/beaglebone-yocto"
BOOTTARGETPATH="${HOME_PATH}/mnt/boot"
ROOTFSTARGETPATH="${HOME_PATH}/mnt/rootfs"
ROOTFS_NAME="core-image-sato-dev-beaglebone-yocto.tar.bz2"


cp ${IMAGEPATH}/MLO ${BOOTTARGETPATH}
cp ${IMAGEPATH}/zImage ${BOOTTARGETPATH}
cp ${IMAGEPATH}/uImage ${BOOTTARGETPATH}
cp ${IMAGEPATH}/u-boot.img ${BOOTTARGETPATH}
cp ${IMAGEPATH}/am335x-boneblack.dtb ${BOOTTARGETPATH}

rm -rf ${ROOTFSTARGETPATH}/*
tar -xf ${IMAGEPATH}/${ROOTFS_NAME} -C ${ROOTFSTARGETPATH}
umount -l ${BOOTTARGETPATH}
umount -l ${ROOTFSTARGETPATH}
