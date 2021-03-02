#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int person1 = 1;
    int person1_answer = 0;
    int person2 = 0;
    int person2_answer = 0;
    int person3 = 3;
    int person3_answer = 0;
    int count = 0;
    int temp[3];

    for (int i = 0; i < answers.size(); i++) {
        if (person1 == 6)
            person1 = 1;
        if (answers[i] == person1)
            person1_answer++;
        person1++;
    }
    for (int i = 0; i < answers.size(); i++) {
        if (person2 == 6)
            person2 = 1;
        if (person2 == 2)
            person2 = 3;
        if (i % 2 == 0) {
            if (answers[i] == 2)
                person2_answer++;
        }
        else if (i % 2 == 1) {
            if (answers[i] == person2)
                person2_answer++;
        }
        if (i % 2 == 0)
            person2++;
    }
    for (int i = 0; i < answers.size(); i++) {
        if (person3 == 6)
            person3 = 3;
        if (answers[i] == person3)
            person3_answer++;
        count++;
        if (count == 2 && person3 == 3) {
            person3 = 1;
            count = 0;
        }
        else if (count == 2 && person3 == 2) {
            person3 = 4;
            count = 0;
        }
        else if (count == 2) {
            person3++;
            count = 0;
        }
    }
    
    temp[0] = person1_answer;
    temp[1] = person2_answer;
    temp[2] = person3_answer;
    int max = temp[0];

    if (person1_answer == person2_answer && person3_answer > person1_answer) {
        answer.push_back(3);
        return answer;
    }

    for (int i = 0; i < 3; i++) {
        if (max < temp[i]) {
            max = temp[i];
            answer.pop_back();
            answer.push_back(i + 1);
        }
        else if (max == temp[i]) {
            answer.push_back(i + 1);
        }
    }

    cout << person1_answer << endl;
    cout << person2_answer << endl;
    cout << person3_answer << endl;

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<int> answers = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2 };
    vector<int>answer=solution(answers);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    
}