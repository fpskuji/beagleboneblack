How to use:
1. Set HOME_PATH and WORKSPACE_PATH in 1_build_FW.sh based on your own configuration
2. Set BOOTPATH and ROOTFSPATH in mount_sdcard.sh based on your own configuration
3. Set PATH variables in copy_FW.sh
4. Execute 1_build_FW.sh script to build image
5. Execute 2_upgrade_FW.sh script with root permissions to mount SD card and copy the necessary files for boot-up

Note:
Beaglebone Black requires uImage kernel type and 1_build_FW.sh will automatically create it.