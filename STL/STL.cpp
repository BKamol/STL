#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>

using namespace std;

int find(const vector<string>& a_vector, const string& target)
{
    for (int i = 0; i < a_vector.size(); i++)
    {
        if (a_vector[i] == target)
            return i;
    }
    return a_vector.size();
}

void replace(vector<string>& a_vector, const string& old_item, const string& new_item)
{
    for (int i = 0; i < a_vector.size(); i++)
    {
        if (a_vector[i] == old_item)
            a_vector[i] = new_item;
    }
}

void print_vector(vector<string>& a_vector)
{
    for (int i = 0; i < a_vector.size(); i++)
        cout << a_vector[i] << ' ';
    cout << endl;
}

template <typename T>
void delete_item(vector<T>& a_vector, const T& target)
{
    typename vector<T>::iterator it = a_vector.begin();
    while (it != a_vector.end())
    {
        if (*(it) == target)
        {
            a_vector.erase(it);
            return;
        }
        it++;
    }
}

void print_list(list<int>& requests)
{
    list<int>::iterator it = requests.begin();
    while (it != requests.end())
    {
        cout << *(it) << ' ';
        it++;
    }
    cout << endl;
}

void lru(list<int>& requests, int request, int size)
{
    list<int>::iterator it = requests.begin();
    bool is_deleted = false;
    while (!is_deleted && it != requests.end())
    {
        if (*it == request)
        {
            requests.erase(it);
            is_deleted = true;
        }  
        if (!is_deleted) it++;
    }
    requests.push_front(request);
    requests.resize(size);
    print_list(requests);
}

map<pair<int, int>, double> create_matrix(int size)
{
    map<pair<int, int>, double> result;
    double data;
    cout << "Input " << size * size << " values of matrix: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> data;
            if (data != 0)
                result[make_pair(i, j)] = data;
        }
    }
    return result;
}

double sled(map<pair<int, int>, double>& M, int size)
{
    double result = 0;
    map<pair<int, int>, double>::iterator it = M.begin();
    while (it != M.end())
    {
        if (it->first.first == it->first.second)
            result += it->second;
        it++;
    }

    return result;
}

void print_matrix(map<pair<int, int>, double>& M, int size)
{
    map<pair<int, int>, double>::iterator it = M.begin();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (it == M.end())
                cout << 0 << ' ';
            else if (it != M.end() && it->first == make_pair(i, j))
            {
                cout << it->second << ' ';
                it++;
            }
            else
            {
                cout << 0 << ' ';
            }  
        }
        cout << endl;
    }
}

int main()
{
    /*vector<string> v = { "abc", "def", "ghi", "jkl", "abc"};
    cout << find(v, "abc") << ' ' << find(v, " ") << endl;*/

    //replace(v, "abc", "cba");
    //print_vector(v);

    /*delete_item<string>(v, "jkl");
    print_vector(v);*/


    list<int> requests;
    requests.resize(4, -1);
    for (int i = 0; i < 8; i++)
    {
        lru(requests, 1, 4);
    }
    print_list(requests);

    /*int size = 3;
    map<pair<int, int>, double> M = create_matrix(3);
    cout << sled(M, size) << endl;
    print_matrix(M, size);
    cout << M.size() << endl;*/


}