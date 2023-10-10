/* W. H. Bell
** A demonstration of a class template.  This is a class contains an 
** array as its central data member.
*/

#include "Array.h"

/** Constructors ********************/
template <class T> Array<T>::Array(int size) {
  m_array = new T[size];
  m_size = size;
}

/** Destructor **********************/
template <class T> Array<T>::~Array() {
  delete m_array;
}

/** Public member functions *********/
template <class T> int Array<T>::getSize(void) {
  return m_size;
}

template <class T> T Array<T>::getElement(int element) {
  if(element<m_size && element>=0) {
    return m_array[element];
  }
  else {
    return 0;
  }
}

template <class T> void Array<T>::setElement(int element, T value) {
  if(element<m_size && element>=0) {
    m_array[element]=value;
  }
}

/* Templates instantiations needed by g++ */
template class Array<char>;
template class Array<int>;
template class Array<float>;
template class Array<double>;
