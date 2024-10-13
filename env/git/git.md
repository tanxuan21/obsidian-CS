在向远程推送时https，
```shell
git push origin main
```
遇到远程意外挂断：
```shell
枚举对象中: 216, 完成.
对象计数中: 100% (216/216), 完成.
使用 8 个线程进行压缩
压缩对象中: 100% (173/173), 完成.
错误：RPC 失败。HTTP 400 curl 22 The requested URL returned error: 400
send-pack: unexpected disconnect while reading sideband packet
写入对象中: 100% (216/216), 130.86 MiB | 22.44 MiB/s, 完成.
总共 216（差异 23），复用 0（差异 0），包复用 0
致命错误：远端意外挂断了
Everything up-to-date
```

是因为暂存取不够大，一劳永逸的解决：

```shell
git config --global http.postBuffer 5242880000
```
 将暂存区大小更改为5G即可。
 