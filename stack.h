template <class ItemType>
ItemType Stack<ItemType>::size(){
    return myTop + 1;
}


//identical

template <class ItemType>
bool Stack<ItemType>::identical(const Stack<ItemType> &otherStack) const {
    if(this->myTop != otherStack.myTop){
        return false;
    }
    for(int i = 0; i <= myTop; i++){
        if (this->myArray[i] != otherStack.myArray[i]) {
            return false;
        }
    }
    return true;
}
