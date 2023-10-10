c     W. H. Bell
c     A fortran subroutine and function to demonstrate the
c     principle of wrapping.
c
      SUBROUTINE COMMONS
      IMPLICIT NONE
      INCLUDE 'FORTRAN.INC'

      INTEGER I,J

      DO I=1,3
         DO J=1,2
            PRINT *,'COMMONS::INTARRAY(',I,',',J,')=',INTARRAY(I,J)
         ENDDO
      ENDDO
      
      DO I=1,2
         DO J=1,3
            PRINT *,'COMMONS::REALARRAY(',I,',',J,')=',REALARRAY(I,J)
         ENDDO
      ENDDO

      PRINT *,'SOMESTRING=',SOMESTRING
      
      RETURN
      END


      FUNCTION CALL_BACK(A,NAME)
      IMPLICIT NONE
      REAL A, C, CALL_BACK, MULT_A
      CHARACTER*(*) NAME

      PRINT *,'CALL_BACK::NAME=',NAME

      C = MULT_A(A)

      PRINT *,'CALL_BACK::C=',C
      
      CALL_BACK = C
      RETURN
      END
