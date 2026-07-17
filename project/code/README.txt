代码在vscode上编写，由于vscode默认是文件之间独立编译，所以我调整了默认的vscode工程配置文件，这里也一并给出（修改部分如下）
	在tasks.json中这一行（"${fileDirname}\\${fileBasenameNoExtension}.exe",）后
	新增
	"-std=c++11",
        "-finput-charset=UTF-8",
        "-fexec-charset=GBK"
	在vscode中不能以Run code选项运行，而应是 运行c++文件