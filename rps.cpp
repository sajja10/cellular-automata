#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct input
{
    char c;
    int r, p, s;
};

struct node
{
    char value;
    int id;
    struct node *r;
    struct node *p;
    struct node *s;
};

map<set<int>, struct node *> m;

struct node *makeNode(int id, char value, struct node *rock, struct node *paper, struct node *scissor)
{
    struct node *st = (struct node *)malloc(sizeof(struct node));
    st->id = id;
    st->value = value;
    struct node *r = rock;
    struct node *p = paper;
    struct node *s = scissor;
    return st;
}

vector<struct input> v;

char findMax(int n)
{
    int count_r = 0, count_p = 0, count_s = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].c == 'R')
        {
            count_r++;
        }
        else if (v[i].c == 'P')
        {
            count_p++;
        }
        else if (v[i].c == 'S')
        {
            count_s++;
        }
    }

    char inp;
    if (count_r == count_p && count_p == count_s && count_s == count_r)
    {
        inp = 'R';
    }
    else if (count_r == count_p && count_s > count_r)
    {
        inp = 'R';
    }
    else if (count_r == count_p && count_s < count_r)
    {
        inp = 'P';
    }
    else if (count_r == count_s && count_p > count_r)
    {
        inp = 'S';
    }
    else if (count_r == count_s && count_p < count_r)
    {
        inp = 'P';
    }
    else if (count_s == count_p && count_r > count_s)
    {
        inp = 'P';
    }
    else if (count_s == count_p && count_r < count_s)
    {
        inp = 'R';
    }
    else if (count_r > count_p && count_r > count_s)
    {
        inp = 'P';
    }
    else if (count_p > count_r && count_p > count_s)
    {
        inp = 'S';
    }
    else if (count_s > count_p && count_s > count_r)
    {
        inp = 'R';
    }
    return inp;
}

char findinpt(int count_r, int count_p, int count_s)
{
    char inp;
    if (count_r == count_p && count_p == count_s && count_s == count_r)
    {
        inp = 'R';
    }
    else if (count_r == count_p && count_s > count_r)
    {
        inp = 'R';
    }
    else if (count_r == count_p && count_s < count_r)
    {
        inp = 'P';
    }
    else if (count_r == count_s && count_p > count_r)
    {
        inp = 'S';
    }
    else if (count_r == count_s && count_p < count_r)
    {
        inp = 'P';
    }
    else if (count_s == count_p && count_r > count_s)
    {
        inp = 'P';
    }
    else if (count_s == count_p && count_r < count_s)
    {
        inp = 'R';
    }
    else if (count_r > count_p && count_r > count_s)
    {
        inp = 'P';
    }
    else if (count_p > count_r && count_p > count_s)
    {
        inp = 'S';
    }
    else if (count_s > count_p && count_s > count_r)
    {
        inp = 'R';
    }
    return inp;
}

int z = 2;
void dfs(struct node *init, char inp, set<int> vec)
{
    set<int>::iterator itr;

    set<int> vi_r;
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        if (v[*itr - 1].c == 'R')
        {
            if (inp == 'R')
            {
                vi_r.insert(v[*itr - 1].r);
            }
            else if (inp == 'P')
            {
                vi_r.insert(v[*itr - 1].p);
            }
            else if (inp == 'S')
            {
                vi_r.insert(v[*itr - 1].s);
            }
        }
    }
    if (vi_r.size() == 0)
    {
        init->r = NULL;
    }
    else
    {
        if (m.find(vi_r) != m.end())
        {
            init->r = m[vi_r];
        }
        else
        {
            int count_r_r = 0, count_p_r = 0, count_s_r = 0;
            for (itr = vi_r.begin(); itr != vi_r.end(); itr++)
            {
                if (v[*itr - 1].c == 'R')
                {
                    count_r_r++;
                }
                else if (v[*itr - 1].c == 'P')
                {
                    count_p_r++;
                }
                else if (v[*itr - 1].c == 'S')
                {
                    count_s_r++;
                }
            }

            char out_r = findinpt(count_r_r, count_p_r, count_s_r);
            init->r = makeNode(z, out_r, NULL, NULL, NULL);
            z++;
            m[vi_r] = init->r;
            dfs(init->r, out_r, vi_r);
        }
    }
    //////////////////////////////////////////////////////
    set<int> vi_p;
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        if (v[*itr - 1].c == 'P')
        {
            if (inp == 'R')
            {
                vi_p.insert(v[*itr - 1].r);
            }
            else if (inp == 'P')
            {
                vi_p.insert(v[*itr - 1].p);
            }
            else if (inp == 'S')
            {
                vi_p.insert(v[*itr - 1].s);
            }
        }
    }
    if (vi_p.size() == 0)
    {
        init->p = NULL;
    }
    else
    {
        if (m.find(vi_p) != m.end())
        {
            init->p = m[vi_p];
        }
        else
        {
            int count_r_p = 0, count_p_p = 0, count_s_p = 0;
            for (itr = vi_p.begin(); itr != vi_p.end(); itr++)
            {
                if (v[*itr - 1].c == 'R')
                {
                    count_r_p++;
                }
                else if (v[*itr - 1].c == 'P')
                {
                    count_p_p++;
                }
                else if (v[*itr - 1].c == 'S')
                {
                    count_s_p++;
                }
            }

            char out_p = findinpt(count_r_p, count_p_p, count_s_p);
            init->p = makeNode(z, out_p, NULL, NULL, NULL);
            z++;
            m[vi_p] = init->p;
            dfs(init->p, out_p, vi_p);
        }
    }
    //////////////////////////////////////////////////////
    set<int> vi_s;
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        if (v[*itr - 1].c == 'S')
        {
            if (inp == 'R')
            {
                vi_s.insert(v[*itr - 1].r);
            }
            else if (inp == 'P')
            {
                vi_s.insert(v[*itr - 1].p);
            }
            else if (inp == 'S')
            {
                vi_s.insert(v[*itr - 1].s);
            }
        }
    }
    if (vi_s.size() == 0)
    {
        init->s = NULL;
    }
    else
    {
        if (m.find(vi_s) != m.end())
        {
            init->s = m[vi_s];
        }
        else
        {
            int count_r_s = 0, count_p_s = 0, count_s_s = 0;
            for (itr = vi_s.begin(); itr != vi_s.end(); itr++)
            {
                if (v[*itr - 1].c == 'R')
                {
                    count_r_s++;
                }
                else if (v[*itr - 1].c == 'P')
                {
                    count_p_s++;
                }
                else if (v[*itr - 1].c == 'S')
                {
                    count_s_s++;
                }
            }

            char out_s = findinpt(count_r_s, count_p_s, count_s_s);
            init->s = makeNode(z, out_s, NULL, NULL, NULL);
            z++;
            m[vi_s] = init->s;
            dfs(init->s, out_s, vi_s);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    struct input a;

    for (int i = 0; i < n; i++)
    {
        char c;
        int r, p, s;
        cin >> c >> r >> p >> s;
        a.c = c;
        a.r = r;
        a.p = p;
        a.s = s;
        v.push_back(a);
    }

    set<int> vi;
    for (int i = 1; i <= n; i++)
    {
        vi.insert(i);
    }

    char inp = findMax(n);
    struct node *init = makeNode(1, inp, NULL, NULL, NULL);
    m[vi] = init;
    dfs(init, inp, vi);
    printf("%d\n",m.size());
    char str[m.size()][5];
    map<int,string> mi;
    int i=0;
    for (map<set<int>, struct node *>::iterator it = m.begin(); it != m.end(); ++it)
    {
        str[i][0]=(*it).second->value;
        //cout << (*it).second->value << ":";
        //cout << (*it).second->id << ":";
        if ((*it).second->r != NULL)
        {
            //cout << (*it).second->r->id;
            int a=(*it).second->r->id+48;
            str[i][1]=char(a);
        }
        else
        {
            //cout << 1;
            str[i][1]='1';
        }
        if ((*it).second->p != NULL)
        {
            //cout << (*it).second->p->id;
            int a=(*it).second->p->id+48;
            str[i][2]=char(a);
        }
        else
        {
            //cout << 1;
            str[i][2]='1';
        }
        if ((*it).second->s != NULL)
        {
            //cout << (*it).second->s->id;
            int a=(*it).second->s->id+48;
            str[i][3]=char(a);
        }
        else
        {
            //cout << 1;
            str[i][3]='1';
        }
        str[i][4]='\0';
        mi[(*it).second->id]=str[i];
        //cout << endl;
        i++;
    }

    for (map<int, string>::iterator it = mi.begin(); it != mi.end(); ++it)
    {
        for(int i=0;i<4;i++)
        {
            if(i!=0)
        cout<<int((*it).second[i])-48<<" ";
        else
        cout<<(*it).second[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}