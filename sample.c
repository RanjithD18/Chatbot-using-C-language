#include <stdio.h>
#include <string.h>
struct arrays{
        char str[100];
        char str1[100][100];
        int len;
}x,y;
struct quesans{
        char ques[100];
        char ans[100];
}q1[3];
struct arrays stringsplit(struct arrays x){
        int init_size = strlen(x.str);
	char delim[] = " ";
	char *ptr = strtok(x.str, delim);
        int i=0;
	while(ptr != NULL)
	{
                strcpy(x.str1[i], ptr);
                i++;
		ptr = strtok(NULL, delim);
	}
        x.len=i;
        return x;
}
void storeques(struct quesans q1[]){
        FILE *f;
        f=fopen("question.txt","a+");
        char buf[100];
        // fgets(buf, sizeof(buf), f);
        // printf("%s",buf)
        int i=0;
        while (!feof(f)) {
                fgets(buf, sizeof(buf), f);
                strcpy(q1[i].ques,buf);
                // printf("%s",q1[i].ques);
                i++;
    }
}
void storeans(struct quesans q1[]){
        FILE *f;
        f=fopen("answer.txt","a+");
        char buf[100];
        // fgets(buf, sizeof(buf), f);
        // printf("%s",buf)
        int i=0;
        while (!feof(f)) {
                fgets(buf, sizeof(buf), f);
                strcpy(q1[i].ans,buf);
                // printf("%s",q1[i].ans);
                i++;
    }
}
void comparetwo(struct arrays x,struct arrays y,struct quesans q1[],int place){
        int n=0;
        for(int i=0;i<x.len;i++){
                for(int j=0;j<y.len;j++){
                        if(strcmp(x.str1[i],y.str1[j])==0){
                                // printf("%s ",y.str1[j]);
                                n++;
                        }
                }
        }
        if(y.len==n){
                printf("%s",q1[place].ans);
        }
}
int main()
{
        // strcpy(q1.ques,"what your name");
        storeques(q1);
        // strcpy(q1[0].ans,"Im Ranjith");
        storeans(q1);
        
        fgets(x.str, sizeof(x.str), stdin);
        x.str[strlen(x.str)-1]=' ';
        
        
        x=stringsplit(x);
        for(int i=0;i<3;i++){
                strcpy(y.str,q1[i].ques);
                y.str[strlen(y.str)-1]=' ';
                y=stringsplit(y);
                comparetwo(x,y,q1,i);
                }
	return 0;
}