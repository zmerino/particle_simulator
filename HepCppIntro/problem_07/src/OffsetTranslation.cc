#include "OffsetTranslation.h"

OffsetTranslation::OffsetTranslation(double *vec) {
  m_offset = new double[2];
  m_offset[0] = vec[0];
  m_offset[1] = vec[1];
}

OffsetTranslation::~OffsetTranslation() {
  delete m_offset;
}

void OffsetTranslation::translate(double *vec) {
  vec[0] += m_offset[0];
  vec[1] += m_offset[1];
}

void OffsetTranslation::reverse(double *vec) {
  vec[0] -= m_offset[0];
  vec[1] -= m_offset[1];
}
