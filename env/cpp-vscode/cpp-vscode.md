
# 邏輯

首先要理解vscode的調適邏輯。這是很多教程爛的地方。他只講操作不講為啥，這個配置是幹嘛的。

首先，使用vscode的工作區的運行，也就是vscode最左側工具欄`運行和調適`運行代碼，要讀取`.vscode`文件夾下的配置。
使用vscode直接通過文件夾打開，vscode是不會主動給妳創建`.vscode`文件夾的。你可以自己創建。也可以使用插件或者圖形界面創建。

> 注意它以`.`開頭，是個隱藏文件，在資源管理器中需要打開顯示隱藏文件才可看到（自行查閱各自平台下的快捷鍵）

最重要的兩個配置文件：

```shell
.vscode
   ├── launch.json
   └── tasks.json
```


啟動配置`launch.json`是管理啟動的。也就是編譯完了，有一個二進制可執行文件了，你啟動時生效的啟動配置。

任務配置`tasks.json`是管理任務的。什麼任務都可以，本質上就是代理你去命令行工具去輸入指令。在這篇文章的主題下，我們要配置的任務就是編譯cpp文件。

# visual-studio-code

該下的插件都下一遍。

![[iShot_2024-09-25_11.31.19.png]]
# Mac 


先下載完整的xcode以及命令行工具。這部分略過

### tasks.json

任務配置可以通過默認的來。菜單欄終端 -> 配置任務 -> 選擇c/c++ 啟動
但是我的mac裡沒有，沒問題，我大不了自己寫。

這裡我配置了一個任務。最重要的就是這三個屬性，其實只有這三個屬性就可以了。

`label`表示這個任務的標籤，你可以寫任何你喜歡的字符串，用於`launch.json`找到啟動前的編譯任務。
`command`就是命令主體
`args`是命令的參數。參數中帶`-`的是選項，具體的含義請自行查閱文檔和ai工具。`${fileDirname}/${fileBasenameNoExtension}`是vscode自己的站位符，`${fileDirname}`表示當前激活的文件路徑，也就是你所正在編輯的代碼文件的路徑。
`${fileBasenameNoExtension}`就是當前文件去除擴展名的文件名。
當然還有更多更靈活的站位符，這些可以尋找[vscode官網](https://code.visualstudio.com/docs/editor/variables-reference)查閱


```json
{
	"tasks":[
		{
			"label": "c/c++ for mac",
			"command": "/usr/bin/clang++",
			"args": [
			"-fcolor-diagnostics",
			"-fansi-escape-codes",
			"-g",
			"${file}",
			"-o",
			"${fileDirname}/${fileBasenameNoExtension}"
			],
		},
	],
	"version" : "2.0.0"
}
```


總的來說，這個任務就是，將當前正在編輯的cpp文件，編譯為與自己同名的可執行文件，並且編譯到與自己同一個根目錄下。

### launch.json

菜單欄運行 -> 添加配置 -> 選擇`c/c++ lldb啟動`直接一鍵添加。

```json
{
	"configuration" : [
		{
			"name": "c/c++ for mac 測試",
			"type": "cppdbg",
			"request": "launch",
			"program": "${fileDirname}/${fileBasenameNoExtension}",
			"args": [],
			"stopAtEntry": false,
			"cwd": "${fileDirname}",
			"environment": [],
			"externalConsole": true,
			"MIMode": "lldb",
			"preLaunchTask": "c/c++ for mac",
		},
	]
}
```

這裡的配置修改即可，不建議自己手寫。
首先添加`preLaunchTask`屬性，字面意義就是在啟動前的任務。裡面填寫你任務的`label`屬性。不寫這個，vscode會報錯提示你配置tasks。

> 這裡讀者是否注意到，完全可以配置許多個`tasks`對象，可以針對不同的操作系統環境，針對不同的需求。這都是非常靈活的。

`program`就是啟動的可執行文件。編譯出來在哪，你就添什麼。否則會報錯找不到可執行文件。

`args` 是你向可執行文件傳入的參數。

`externalConsole`是打開外部終端，建議打開外部終端。
``
其他的屬性都默認活著不是非常重要。

不出意外的話，你應該可以完整的運行調適代碼了。


