#pragma once

NODE* CreateNode(int data);

List* CreateList(NODE* p_node);

bool AddHead(List* L, int data);

bool AddTail(List* L, int data);

void RemoveHead(List* L);

void RemoveTail(List* L);

void RemoveAll(List*& L);

void PrintList(List* L);

int CountElements(List* L);

List* ReverseList(List* L);

void RemoveDuplicate(List*& L);

bool RemoveElement(List*& L, int key);
