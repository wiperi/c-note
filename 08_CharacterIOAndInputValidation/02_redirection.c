/* 
在vscode中使用重定向

Winsows PowerShell不支持 < 作为重定向操作符，只能使用管道操作符 | 搭配 Get-Content 命令来实现相同的效果
终端：
PS C:\Users\15617\Documents\92 My Github\C-Primer-Plus-handbook> Get-Content input.txt | .\bin\fff.exe
666

 */