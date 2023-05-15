HOME_PATH="/home/gaviolam"
WORKSPACE_PATH="linux_kernel_src/dunfell/poky"

cd ${HOME_PATH}/${WORKSPACE_PATH}

source oe-init-build-env

bitbake core-image-sato-dev

pushd tmp/deploy/images/beaglebone-yocto

mkimage -A arm -O linux -T kernel -C none -a 0x82000000 -e 0x82000000 -n "Linux kernel" -d ./zImage uImage
