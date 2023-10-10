      SUBROUTINE LORENTZ(PA,PI,PF)
      IMPLICIT NONE
      REAL PA(4)                ! Boost vector
      REAL PI(4)                ! Initial vector
      REAL PF(4)                ! Final vector
      REAL SMS, SCAL4, SCALG, SRS, GM, DOT1, DOT2
      INTEGER J

      SMS=SCALG(PA(1),PA(1))
      SRS=SQRT(SMS)
      GM=SRS*PA(4)+SMS
      DOT1=SCAL4(PA(1),PI(1))
      DOT2=SCALG(PA(1),PI(1))
      DO J=1,3
         PF(J)=PI(J)-PA(J)*(PI(4)/SRS)+PA(J)*DOT1/GM
      END DO
      PF(4)=DOT2/SRS
      RETURN
      END

c     -----------------------------------------------------

      FUNCTION SCALG(A,B)
      IMPLICIT NONE
      REAL A(4),B(4),SXS,SCALG
 
      SXS=A(4)*B(4)-A(1)*B(1)-A(2)*B(2)-A(3)*B(3)
      SCALG=SXS
      RETURN
      END

c     -----------------------------------------------------

      FUNCTION SCAL4(A,B)
      REAL A(4),B(4),SXS,SCAL4 

      SXS=A(1)*B(1)+A(2)*B(2)+A(3)*B(3)
      SCAL4=SXS
      RETURN
      END
