#include<bits/stdc++.h>
using namespace std;
#define N 100000

typedef struct Person{
    char gender;
    string monther_id;
    string father_id;
} Person;

unordered_set<string> GetAncestors(const string& id, unordered_map<string, Person>& peoples){
    unordered_set<string> ancestors;
    queue<pair<string, int>> q;
    if (!peoples.count(id)) return ancestors;
    auto it = peoples.find(id);
    Person p = it->second;
    if (p.monther_id != "-1") q.push(make_pair(p.monther_id, 2));
    if (p.father_id != "-1") q.push(make_pair(p.father_id, 2));
    while (!q.empty()){
        auto p = q.front();
        q.pop();
        if (p.second > 5) continue;
        if (ancestors.count(p.first)) continue;
        ancestors.insert(p.first);
        auto it_current = peoples.find(p.first);
        if (it_current == peoples.end()) continue;
        Person &currentPerson = it_current->second;
        if (currentPerson.monther_id != "-1") q.push(make_pair(currentPerson.monther_id, p.second + 1));
        if (currentPerson.father_id != "-1") q.push(make_pair(currentPerson.father_id, p.second + 1));
    }
    return ancestors;
}

int main(){
    int T;
    cin >> T;
    unordered_map<string, Person> peoples;
    while (T--){
        string id, monther_id, father_id;
        char gender;
        cin >> id >> gender >> monther_id >> father_id;
        peoples[id] = {gender, monther_id, father_id};
        if (father_id != "-1" && !peoples.count(father_id))
            peoples[father_id] = {'M', "-1", "-1"};
        if (monther_id != "-1" && !peoples.count(monther_id))
            peoples[monther_id] = {'F', "-1", "-1"};
    }
    int K;
    cin >> K;
    while (K--){
        string id1, id2;
        cin >> id1 >> id2;
        if (peoples[id1].gender == peoples[id2].gender)
            cout << "Never Mind" << endl;
        else{
            unordered_set<string> ancestors1 = GetAncestors(id1, peoples);
            unordered_set<string> ancestors2 = GetAncestors(id2, peoples);
            bool flag = false;
            for (auto it1 : ancestors1)
                if (ancestors2.count(it1)){
                    flag = true;
                    break;
                }
            if (!flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
