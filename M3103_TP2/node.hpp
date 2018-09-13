#pragma once
#include <iostream>

template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_NextNode;
public:
    //constructeur
    CNode(const T &i = T(), CNode* ptr = nullptr):
        m_Data (i), m_NextNode (ptr){}
    //destructeur
    ~CNode()
    {
        delete m_NextNode;
    }
    //get & set
    const T &GetDATA() const{
        return m_Data;
    }
    CNode* GetNextNode() const{
        return m_NextNode;
    }
    void SetData(const T &Data){
        m_Data = Data ;
    }
    void SetNextNode(CNode* Next){
        m_NextNode = Next;
    }
};//CNode



