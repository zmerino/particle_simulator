#ifndef OFFSET_TRANSLATION_HH
#define OFFSET_TRANSLATION_HH

#include "ITranslation.h"

class OffsetTranslation : public ITranslation {
 public:
  OffsetTranslation(double *offset); // array with 2 elements
  ~OffsetTranslation();

  virtual void translate(double *vec); // array with 2 elements
  virtual void reverse(double *vec); // array with 2 elements

 private:
  double *m_offset;
};

#endif
