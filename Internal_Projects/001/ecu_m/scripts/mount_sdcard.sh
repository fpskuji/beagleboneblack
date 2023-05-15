
DEVPATH="/dev/sd"
BOOTPATH="/home/gaviolam/mnt/boot"
ROOTFSPATH="/home/gaviolam/mnt/rootfs"


for var in 'b' 'c' 'd' 'e' 'f' 'g'
do
	fdisk -l | grep Disk | grep ${DEVPATH}${var}
	if [ $? -eq 0 ]
	then
		FULLMPATH1="${DEVPATH}${var}1"
		FULLMPATH2="${DEVPATH}${var}2"
		echo "sd${var}"
	fi
done

mount ${FULLMPATH1} ${BOOTPATH}
mount ${FULLMPATH2} ${ROOTFSPATH}

