#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include <ctype.h>
struct arrays{
        char str[100];
        char str1[100][100];
        int len;
}x,y;
struct quesans{
        char ques[100];
        char ans[100];
        struct quesans *next;
};
struct quesans* q1=NULL;
struct details{
        char name[30];
}na[3];
void storename(struct details x[]){
        FILE *f;
        f=fopen("detailname.txt","a+");
        char buf[100];
        int i=0;
        while (!feof(f)) {
                fgets(buf, sizeof(buf), f);
                buf[strlen(buf)-1]='\0';
                strcpy(x[i].name,buf);
                i++;
        }
        fclose(f);
}
struct arrays stringsplit(struct arrays x){
        int init_size = strlen(x.str);
	char delim[] = " '?";
        int j = 0;
        while (x.str[j]) {
                x.str[j] = tolower(x.str[j]);
                j++;
        }
//     for (int i = 0; i < j; i++){
//         printf("%c", x.str[i]);}
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
void push(char *value,char *value1) {
    struct quesans *newNode;
    newNode = (struct quesans *)malloc(sizeof(struct quesans));
    strcpy(newNode->ques,value);
    strcpy(newNode->ans,value1);
    if (q1 == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = q1;
    }
    q1 = newNode;
}
void storeques(struct quesans q1[]){
        FILE *f;
        f=fopen("question.txt","a+");
        FILE *f1;
        f1=fopen("answer.txt","a+");
        char buf[100];
        char buf1[100];
        int i=0;
        while (!feof(f)) {
                fgets(buf, sizeof(buf), f);
                fgets(buf1, sizeof(buf1), f1);
                // strcpy(q1[i].ques,buf);
                push(buf,buf1);
                i++;
        }
}
bool comparetwo(struct arrays x,struct arrays y,struct quesans *q1){
        int n=0;
        for(int i=0;i<x.len;i++){
                for(int j=0;j<y.len;j++){
                        if(strcmp(x.str1[i],y.str1[j])==0){
                                n++;
                        }
                }
        }
        if(y.len==n){
                printf("%s",q1->ans);
                return true;
        }
        else{
                return false;
        }
}
bool comparebye(struct arrays x,char y[]){
        int n=0;
        for(int i=0;i<x.len;i++){
                        if(strcmp(x.str1[i],y)==0){
                                n++;
                        }
        }
        if(1==n){
                return true;
        }
        else{
            return false;
        }
}
bool result(struct arrays x){
    struct quesans *temp = q1;
        while (temp->next != NULL) {
            strcpy(y.str,temp->ques);
            y.str[strlen(y.str)-1]=' ';
                y=stringsplit(y);
                if(comparetwo(x,y,temp)){
                        return true;
                }
            temp = temp->next;
        }
        strcpy(y.str,temp->ques);
            y.str[strlen(y.str)-1]=' ';
                y=stringsplit(y);
                if(comparetwo(x,y,temp)){
                        return true;
                }
}
void display() {
    if (q1 == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct quesans *temp = q1;
        while (temp->next != NULL) {
            printf("%s--->", temp->ques);
            temp = temp->next;
        }
        printf("%s--->NULL\n\n", temp->ques);
    }
}
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[1000];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);
    if (!strcmp(oldWord, newWord)) {
        return;
    }
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}
void replacename(char x[],char y[]){
        FILE * fPtr;
    FILE * fTemp;
    char path[100];
    char buffer[1000];
    char oldWord[100], newWord[100];


    strcpy(oldWord,x);
    strcpy(newWord,y);
    strcpy(path,"detailname.txt");

    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    if (fPtr == NULL || fTemp == NULL)
    {
        exit(EXIT_SUCCESS);
    }
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        replaceAll(buffer, oldWord, newWord);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);

}
void showtime(){
        time_t rawtime;
        struct tm * timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );
        printf("Now,it's exactly %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}
void showdate(){
        time_t rawtime;
        struct tm * timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );
        printf("Today's date is %02d/%02d/%d\n", timeinfo->tm_mday, timeinfo->tm_mon, (timeinfo->tm_year)-100);
}
int main()
{
        storeques(q1);
        storename(na);
        printf("%s-",na[1].name);
        if(strcmp(na[0].name,"0")==0){
                char name1[30];
                printf("Hii,Myself %s your Personal Assistant\n",na[1].name);
                printf("%s-What's your sweet name?\n",na[1].name);
                scanf("%s",name1);
                // fgets(name1, sizeof(name1), stdin);
                replacename(na[2].name,name1);
                strcpy(na[2].name,name1);
                printf("%s-",na[1].name);
                printf("Hello %s,Nice to meet you\n",na[2].name);
                replacename(na[0].name,"1");
                fgets(x.str, sizeof(x.str), stdin);
        }
        else{
                int i;
                int lower = 0, upper = 4;
                srand(time(0));
                int num = (rand() %(upper - lower + 1)) + lower;
                if(num==0){
                        printf("Welcome back!!\nHow may I help you,%s\n",na[2].name);
                }
                else if(num==1){
                        printf("I was waiting for you,Master %s\nSay what's your command?\n",na[2].name);
                }
                else if(num==2){
                        printf("Heyy %s,What can I do for you?\n",na[2].name);
                }
                else{
                        printf("Your command\n");
                }
        }
        while(1){
            printf("%s-",na[2].name);
            
            fgets(x.str, sizeof(x.str), stdin);
            x.str[strlen(x.str)-1]=' ';
            x=stringsplit(x);
            if(strlen(x.str)==0){
                printf("Ask something..\n");
            }
            else if(comparebye(x,"bye")||comparebye(x,"goodbye")){
                printf("%s-",na[1].name);
                printf("byee tata!!");
                exit(0);
            }
            else if(comparebye(x,"change")&&comparebye(x,"your")&&comparebye(x,"name")){
                char name1[30];
                printf("%s-",na[1].name);
                printf("Give me a Good name: ");
                fgets(name1, sizeof(name1), stdin);
                name1[strlen(name1)-1]='\0';
                replacename(na[1].name,name1);
                // strcpy(na[1].name,name1);
                storename(na);
                printf("%s-",na[1].name);
                printf("%s,That's a cool name\n",na[1].name);
            }
            else if(comparebye(x,"change")&&comparebye(x,"my")&&comparebye(x,"name")){
                char name1[30];
                char n;
                printf("%s-",na[1].name);
                printf("What's your name?\n%s-",na[2].name);
                fgets(name1, sizeof(name1), stdin);
                // scanf("%s",name1);
                name1[strlen(name1)-1]='\0';
                replacename(na[2].name,name1);
                // strcpy(na[2].name,name1);
                storename(na);
                printf("%s-",na[1].name);
                printf("Hello!!Master %s\n",na[2].name);
            }
            else if(comparebye(x,"add")&&comparebye(x,"question")){
                char s1[100];
                char s2[100];
                printf("%s-",na[1].name);
                printf("Enter the Question: ");
                // scanf("%s",s1);
                fgets(s1, sizeof(s1), stdin);
                printf("%s-",na[1].name);
                printf("Enter the Answer: ");
                // scanf("%s",s2);
                fgets(s2, sizeof(s2), stdin);
                printf("%s",s2);
                FILE *f;
                f=fopen("question.txt","a+");
                FILE *f1;
                f1=fopen("answer.txt","a+");
                // s1[strlen(s1)-1]='\0';
                // s2[strlen(s2)-1]='\0';
                fprintf(f,"%s",s1);
                fprintf(f1,"%s",s2);
                fclose(f);
                fclose(f1);
                storeques(q1);
                printf("%s-",na[1].name);
                printf("Successfully added\n");
            }
            else if((comparebye(x,"what")&&comparebye(x,"my")&&comparebye(x,"name"))||(comparebye(x,"who")&&comparebye(x,"I"))){
                printf("%s-",na[1].name);
                printf("My Master,%s\n",na[2].name);
            }
            else if((comparebye(x,"what")&&comparebye(x,"your")&&comparebye(x,"name"))||(comparebye(x,"who")&&comparebye(x,"you"))){
                printf("%s-",na[1].name);
                printf("I'm %s,Your Personal Assistant\n",na[1].name);
            }
            else if(comparebye(x,"time")){
                printf("%s-",na[1].name);
                showtime();
            }
            else if(comparebye(x,"date")){
                printf("%s-",na[1].name);
                showdate();
            }
            else{
                printf("%s-",na[1].name);
                bool q=result(x);
                if(!q){
                        printf("IDK!Since I'm new to Human language Teach me some more dialogue\n");
                }
                }
        }

	return 0;
}