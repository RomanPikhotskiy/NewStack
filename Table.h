#pragma once
#include "Stack.h"
#include <optional>

template<typename T1, typename T2>
class Table{
private:
    size_t _size;
    size_t _count;
    optional<T1>* _col1;
    optional<T2>* _col2;
    string _title1;
    string _title2;
    
public:
    Table(string title1, string title2, size_t size = 10){
        _size = size;
        _count = 0;
        _title1 = title1;
        _title2 = title2;
        _col1 = new optional<T1>[size];
        _col2 = new optional<T2>[size];
    }
    ~Table(){
        delete [] _col1;
        delete [] _col2;
        _col1 = nullptr;
        _col2 = nullptr;
    }
    /// @brief этo функция для добавления элементов в строку
    /// @param elem1 элемент первого столбца
    /// @param elem2 элемент второго столбца
    void AppendRow(optional<T1> elem1, optional<T2> elem2){
        _col1[_count] = elem1;
        _col2[_count] = elem2;
        if (_count + 1 > _size) throw "table is full";
        _count += 1;
    }
    void Print(){
        size_t flag = 5;
        cout << "+";
        for (int i = 0; i < flag * 2 ; i ++){
            if (i == flag) cout << "+";
            cout << "-";
        }
        cout << "+" << endl;
        cout << "|" << setw(flag) << _title1 << "|" << setw(flag) << _title2 << "|" << endl;
        cout << "+";
        for (int i = 0; i < flag * 2 ; i ++){
            if (i == flag) cout << "+";
            cout << "-";
        }
        cout << "+" << endl;
        for ( int i = 0; i < _count; i++){
            cout<< "|";
            if (_col1[i] == nullopt) {
                cout << setw(flag) << "?";
            }
            else {
                cout << setw(flag) << _col1[i].value();
            }
            cout << "|";
            if (_col2[i] == nullopt) {
                cout << setw(flag) << "?";
            }
            else {
                cout << setw(flag) << _col2[i].value();
            }
            cout << "|" << endl;
            //cout << "|" << setw(flag) << ((_col1[i].value() == nullopt) ? _col1[i].value() : "?" )<< "|" << setw(flag) << ((_col2[i].value() == nullopt) ? _col2[i].value() : "?" )<< "|" << endl;
        }
        cout << "+";
        for (int i = 0; i < flag * 2 ; i ++){
            if (i == flag) cout << "+";
            cout << "-";
        }
        cout << "+" << endl;
    }
};