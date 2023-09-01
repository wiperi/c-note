/*
在vscode中使用重定向

Winsows PowerShell不支持 < 作为重定向操作符，只能使用管道操作符 | 搭配 Get-Content 命令来实现相同的效果
终端中操作如下：
PS C:\Users\15617\Documents\92 My Github\C-Primer-Plus-handbook> Get-Content .\08_CharacterIOAndInputValidation\02_input_file.txt | .\bin\02_redirection.exe                             
666

Windows Command Prompt（命令提示符，cmd）支持使用 < 作为重定向操作符，可以直接使用
终端中操作如下：
C:\Users\15617\Documents\92 My Github\C-Primer-Plus-handbook> bin\02_redirection.exe < 08_CharacterIOAndInputValidation\02_input_file.txt
666

 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    char mystr[100];
    scanf("%s", mystr);
    puts(mystr);
    
    return 0;
}