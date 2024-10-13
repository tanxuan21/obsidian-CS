
[官网](https://developer.apple.com/library/archive/documentation/AppleScript/Conceptual/AppleScriptLangGuide/conceptual/ASLR_fundamentals.html#//apple_ref/doc/uid/TP40000983-CH218-SW2)

使用terminal执行命令


```shell
tell application "Terminal"
	activate
	tell window 0
		do script "cd ../ && ls"
	end tell
end tell
```

