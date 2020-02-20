## android系统wifi配置
```
$ adb shell

# su
# chmod -R 777 /data/misc/wifi
# exit

$ adb push wpa_supplicant.conf /data/misc/wifi/wpa_supplicant.conf

$ adb shell svc wifi disable 
$ adb shell svc wifi enable
```
