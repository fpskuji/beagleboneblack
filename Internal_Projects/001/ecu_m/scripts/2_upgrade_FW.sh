
DEVPATH="/dev/sd"
TARGET_PATH="/home/gaviolam/linux_kernel_src/poky/build/tmp/deploy/images/beaglebone-yocto/"
TARGET_FILE="core-image-sato-dev-beaglebone-yocto.wic"

#/home/gaviolam/scripts/mount_sdcard.sh
#/home/gaviolam/scripts/copy_FW.sh

echo "Searching devices"

for var in 'b' 'c' 'd' 'e' 'f' 'g'
do
	fdisk -l | grep Disk | grep ${DEVPATH}${var} > /dev/null
	if [ $? -eq 0 ]
	then
		OF_TARGET="${DEVPATH}${var}"
		#echo "${OF_TARGET}"
	fi
done

echo "Copying kernel image..."
dd if=${TARGET_PATH}${TARGET_FILE} of=${OF_TARGET}
echo "!!!FINISH!!!"
