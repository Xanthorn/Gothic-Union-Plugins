﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZQUEUE_H__VER0__
#define __ZQUEUE_H__VER0__

namespace Gothic_I_Classic {

  template<class T>
  class zQUEUE_ITEM {
  public:
    int empty;
    T* data;
    zQUEUE_ITEM* next;
    zQUEUE_ITEM* prev;

    zQUEUE_ITEM( zQUEUE_ITEM* parent ) {
      data = 0;
      empty = TRUE;
      if( parent ) {
        if( parent->next )
          parent->next->prev = this;
        next = parent->next;
        prev = parent;
        parent->next = this;
      }
      else
        prev = next = NULL;
    }

    int IsEmpty() { 
      return empty; 
    }

    void SetEmpty() {
      empty = TRUE;
      data = 0;
    }

    void SetValue( T* xData ) {
      data = xData;
      empty = FALSE;
    }

    void SetPrev( zQUEUE_ITEM<T>* _prev ) {
      prev = _prev;
    }

    void SetNext( zQUEUE_ITEM<T>* _next ) {
      next = _next;
    }

    ~zQUEUE_ITEM() {}
  };

  template<class T>
  class zQUEUE {
  public:
    int count;
    zQUEUE_ITEM<T>* firstItem;
    zQUEUE_ITEM<T>* lastItem;

    zQUEUE() {
      count = 0;
      firstItem = new zQUEUE_ITEM<T>( NULL );
      firstItem->SetPrev( firstItem );
      firstItem->SetNext( firstItem );
      lastItem = firstItem;
    }

    ~zQUEUE() {
      zQUEUE_ITEM<T>* tmp;
      lastItem = firstItem->prev;
      while( firstItem != lastItem ) {
        tmp = firstItem->next;
        delete firstItem;
        firstItem = tmp;
      }
      delete firstItem;
      firstItem = lastItem = 0;
    }

    T* PopLast() {
      if( lastItem->IsEmpty() )
        return NULL;
      T* data = lastItem->data;
      lastItem->SetEmpty();
      count--;
      if( lastItem != firstItem ) lastItem = lastItem->prev;
      return data;
    }

    T* PopFirst() {
      if( firstItem->IsEmpty() )
        return NULL;
      T* data = firstItem->data;
      firstItem->SetEmpty();
      count--;
      if( firstItem != lastItem )
        firstItem = firstItem->next;
      return data;
    }

    void Push( T* xData ) {
      if( lastItem->next == firstItem ) {
        zQUEUE_ITEM<T>* new_item = lastItem;
        for( int i = 0; i <= 10; i++ )
          new_item = new zQUEUE_ITEM<T>( new_item );
      }
      if( !lastItem->IsEmpty() )
        lastItem = lastItem->next;
      lastItem->SetValue( xData );
      count++;
    }

    void RemoveAll() {
      while( !IsEmpty() ) {
        PopFirst(); 
        count = 0;
      }
    }

    int GetCount() { 
      return count; 
    }

    int IsEmpty() { 
      return firstItem->IsEmpty(); 
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZQUEUE_H__VER0__