#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[500];
char alpha[200];
int j;
int num;

int findReserve(){
	if(strcmp(alpha,"BEGIN"))return 1;
	else if (strcmp(alpha,"END"))return 2;
	else if (strcmp(alpha,"FOR"))return 3;
	else if (strcmp(alpha,"IF"))return 4;
	else if (strcmp(alpha,"THEN"))return 5;
	else if (strcmp(alpha,"ELSE"))return 6;
	else return 0;
	
}

int isColon(char a){
	return a==':';
}
int isEqu(char a){
	return a=='=';
}
int isPlus(char a){
	return a=='+';
}
int isStar(char a){
	return a=='*';
}
int isComma(char a){
	return a==',';
}
int isLParenthesis(char a){
	return a=='(';
}
int isRParenthesis(char a){
	return a==')';
}

int main() {
    FILE *fp;
    int i = 0;
    int result = 0;
    fp=fopen("$input", "r");
    while(fgets(s,500,fp) != NULL) {
    	i = 0, j = 0, result = 0,num=0;
        memset(alpha, 0, 200);
        while (s[i] != '\0') {
            if (isalpha(s[i])) {
                while (isalpha(s[i]) || isdigit(s[i])) {
                    alpha[j++] = s[i];
                    i++;
                }
				i--;
				result = findReserve();
				if (result == 0)printf("Ident(%s)\n",alpha);
				else if (result == 1)printf("Begin\n");
				else if (result == 2)printf("End\n");
				else if (result == 3)printf("For\n");
				else if (result == 4)printf("If\n");
				else if (result == 5)printf("Then\n");
				else if (result == 6)printf("Else\n");
            } else if (isdigit(s[i])){
            	while (isdigit(s[i])){
            		alpha[j++] = s[i];
                    i++;
				}
				i--;
				if (alpha[0]=='0'){
					printf("Unknow\n");
					return 0;
				}
				num=atoi(alpha);
				printf("Int(%d)",num);
			} else if (isColon(s[i])){
				i++;
				if(isEqu(s[i])){
					printf("Assign\n");
				} else {
					i--;
					printf("Colon\n");
				}
			} else if (isPlus(s[i]))printf("Plus\n");
			else if (isStar(s[i]))printf("Star\n");
			else if (isComma(s[i]))printf("Comma\n");
			else if (isLParenthesis(s[i]))printf("LParenthesis\n");
			else if (isRParenthesis(s[i]))printf("RParenthesis\n");
			else {
				printf("Unknow\n");
				break;
			}
			i++;
        }
        return 0;
    }
}

