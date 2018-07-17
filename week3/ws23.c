/*
We can assume that we have access to the
void dynArrayRemoveAt (struct dynArray * dy, int index);
function in Lesson 21.


 void removeDynArr (struct DynArr * da, TYPE test) {
  int i;
  for (i = 0; i < da->size; i++) {
  if (EQ(test, da->data[i])) {
  _dynArrayRemoveAt(da, i);
  return;
  }
  }
 }

 struct DynArr {
 TYPE * data;
 int size;
 int capacity;
};

 */

struct dynArrayIterator {
  struct dynArray * da;
  int currentIndex;
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
  assert(da != 0);        //assert that the struct has been initialized
  assert(itr != 0);       //assert that the pointer has been initialized
  itr->da = da;           //
  itr->currentIndex = 0;  //let's start at the beginning of the dynArray
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
  assert(itr);             //assert that the struct has been initialized
  assert(itr->currentIndex >= 0);             //index is not negative

  if(itr->currentIndex < itr->da->size) //there is at least one more position in array
//QUESTION: in video shows an increment here. Check into the logic.
      return (1);
    else return (0);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
  assert(itr);                                //iterator is not null
  assert(itr->currentIndex >= 0);             //index is not negative
  assert(itr->currentIndex < itr->da->size);  //index within size range
  return (itr->da->data[itr->currentIndex++]);  //post-increment allows one fluid line
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
  assert(itr);                                //iterator is not null
  assert(itr->currentIndex >= 0);             //index is not negative
  assert(itr->currentIndex < itr->da->size);  //index within size range

  _dynArrayRemoveAt(itr->da, itr->currentIndex);
  itr->currentIndex--;    //Decrement the index to prevent jumping elements in the shifted array
}
