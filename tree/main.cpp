#include <iostream>
using namespace std;

//Наша структура
struct node
{
    int data; //Информационное поле
    node *left, *rigth;//Левая и Правая часть дерева
};

node * tree=NULL; //Объявляем переменную, тип которой структура Дерево
node * copytree = NULL;

/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void add(int a,node **t);

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print (node *t,int u);

void copy (node * t, node * &tcop);

int main ()
{
    int n; //Количество элементов
    int s; //Число, передаваемое в дерево
    cout<<"введите количество элементов  ";
    cin>>n; //Вводим количество элементов
    
    for (int i=0;i<n;++i)
    {
        cout<<"ведите число  ";
        cin>>s; //Считываем элемент за элементом
        add(s, &tree); //И каждый кладем в дерево
    }
    
    
    cout<<"ваше дерево\n";
    print(tree,0);
    print (copytree, 0);
    copy(tree, copytree);
    cout << endl;
    print(copytree, 0);
}

void add(int a,node **t)
{
    if ((*t)==NULL) //Если дерева не существует
    {
        (*t)=new node;
        (*t)->data=a;
        (*t)->left=(*t)->rigth=NULL;
        return;
    }
    if (a>(*t)->data) add(a,&(*t)->rigth);
    else add(a,&(*t)->left);
}

void print (node *t,int u)
{
    if (t==NULL) return;
    else
    {
        print(t->left,++u);//С помощью рекурсивного посещаем левое поддерево
        for (int i=0;i<u;++i) cout<<"--";
        cout<<t->data<<endl; //И показываем элемент
        u--;
    }
    print(t->rigth,++u); //С помощью рекурсии посещаем правое поддерево
}
void copy (node * t, node * &tcop)
{
    
    if (t == NULL)
        tcop = NULL;
    else
    { tcop = new node;
        tcop->data = t->data;
        copy(t->left, tcop->left);
        copy(t->rigth, tcop->rigth);
    }
} //end copyTree
