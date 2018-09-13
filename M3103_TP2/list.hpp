#pragma once
#include "node.hpp"
#include <iostream>

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_Tail;
public:
    CList (): m_Head(nullptr), m_Tail(nullptr){}


    ~CList (){ delete m_Head; delete m_Tail; }

   //ajout en tête de liste
    void push_front (const T & val){
        m_Head = new CNode<T> (val, m_Head);
    }
    void push_back (const T & val){
        Add(val,m_Tail);

//        CNode<T>* ptrTmp = new CNode<T>(val, ptrTmp->CNode<T>::GetNextNode());
//        m_Tail = new CNode<T>(val, nullptr);




//        CNode<T>* insert_ptr;
//        CNode<T>* previous_ptr;
//        previous_ptr = nullptr;

//        insert_ptr = new CNode<T>(val);
//        insert_ptr->SetNextNode(previous_ptr->next());
//        previous_ptr->SetNextNode(insert_ptr);

    }

   //affichage
    void Show () const{
        for (CNode<T>* ptr (m_Head); ptr != nullptr; ptr = ptr->CNode<T>::GetNextNode())
            cout << ptr->CNode<T>::GetDATA() << "; ";
    }

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const{
        CNode<T>* ptr (m_Head);
        for (; ptr != nullptr && ptr->CNode<T>::GetDATA() != val; ptr = ptr->CNode<T>::GetNextNode());
        return ptr;
    }
    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* ptr){
//        if(nullptr == ptr ) return;
        CNode<T>* ptrTmp = new CNode<T>(val, ptr->CNode<T>::GetNextNode());
        if (ptr->GetNextNode() == nullptr)
           m_Tail = ptrTmp;
        ptr->SetNextNode(ptrTmp);
    }

    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* pDelete){
        CNode<T>* pFind (m_Head);
        for(; pFind->CNode<T>::GetNextNode() != pDelete ; pFind = pFind->CNode<T>::GetNextNode())
            if(pFind->CNode<T>::GetNextNode() == nullptr)return;
        pFind->CNode<T>::SetNextNode(pDelete->CNode<T>::GetNextNode());
        pDelete->CNode<T>::SetNextNode(nullptr);

        delete pDelete;
    }
};
