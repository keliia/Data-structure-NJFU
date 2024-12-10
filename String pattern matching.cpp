#include <stdio.h>  
#include <string.h>
#define MAXLEN 20
typedef struct {
    char ch[MAXLEN];
    int len;
}SString;
void Create_SString(SString* a);
void Print_SString(SString* a);
int Simple_Match(SString* a, SString* b, int pos);
void Get_Next(SString* a,int *Next);
int KMP_Match(SString* a, SString* b, int pos);
void BODY(void);
int main(int argc,char *argv[])
{
    BODY();
    return 0;
}

void Create_SString(SString* a) {
    scanf("%19s", a->ch, (unsigned)MAXLEN);
    a->len = strlen(a->ch);
}
void Print_SString(SString* a) {
    printf("�ַ���Ϊ:%s", a->ch);
}
int Simple_Match(SString* a, SString* b, int pos) {
    int i = pos-1, j = 0, r = 0;
    while (i < a->len && j < b->len) {
        if (a->ch[i++] == b->ch[j++]);
        else {
            i += -j + 1;
            j = 0;
        }
    }
    if (j == b->len) {
        r = i - b->len + 1;
    }
    return r;
}
void Get_Next(SString* a, int* Next) {
    Next[0] = 0;
    int j = 0, i = 1;
    while (i < a->len) {
        if (a->ch[j] == a->ch[i]) Next[i++] = ++j;
        else {
            if (j == 0) Next[i++] = 0;
            else j = Next[j - 1];
        }
    }
}
int KMP_Match(SString* a, SString* b, int pos) {
    int i = pos-1, j = 0, r = 0;
    int Next[MAXLEN] = { 0 };
    Get_Next(a, Next);
    while (i < a->len) {
        if (a->ch[i] == b->ch[j]) {
            i++; j++;
        }
        else if (j > 0) j = Next[j - 1];
        else i++;
        if (j == b->len) return i - j + 1;
    }
    return 0;
}
void BODY(void) {
    SString a, b;
    int num = 0, pos = 1;
    printf("���������ѡ��:1.��ƥ���㷨\n"
        "               2.KMP�㷨\n"
        "�ҵ�ѡ����:");
    scanf("%d", &num);

    printf("����������:");
    Create_SString(&a);
    printf("������ģʽ��:");
    Create_SString(&b);
    switch (num) {
    case 1:pos=Simple_Match(&a, &b, pos);
    	if(pos) printf("ģʽ����������%d��λ��\n", pos); 
		else printf("���������и�ģʽ��\n");break;
    case 2:pos=KMP_Match(&a, &b, pos);
    	if(pos) printf("ģʽ����������%d��λ��\n", pos); 
		else printf("���������и�ģʽ��\n");break;
    default:printf("��л����!\n");
    }
}
