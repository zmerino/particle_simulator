/* W. H. Bell
** A demonstration of a class template.  This is a class contains an 
** array as its central data member.
*/

#ifndef ARRAY_H
#define ARRAY_H

template <class T> class Array {
public:
  /** Construct an Array of a given side */
  Array(int size);

  /** A destructor to delete dynamically allocated memory */
  ~Array(void);

  /** Get the size of the array */
  int getSize(void);

  /** Get the value of a given element */
  T getElement(int element);

  /** Set the value of a given element */
  void setElement(int element, T value);

protected:
  /** A data member to store the array data */
  T *m_array;

  /** A data member to store the array size */
  int m_size;
};

#endif
