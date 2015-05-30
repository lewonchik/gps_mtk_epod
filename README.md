# gps_mtk_epod

MediaTek GPS EPO Downloader Daemon downloads EPO files from mediatek servers, which is required by MediaTek's GPS HALs for providing correct coordinates. To include this daemon in your system, just add these lines to your init.mt65xx.rc (recommended) or init.rc.

```
service gps_mtk_epod /system/bin/gps_mtk_epod
    user root
    oneshot
    disabled

on post-fs-data
    start gps_mtk_epod
```
