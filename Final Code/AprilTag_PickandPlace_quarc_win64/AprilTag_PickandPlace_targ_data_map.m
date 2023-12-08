    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 9;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (AprilTag_PickandPlace_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.ColorConstant_color
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.undOrder25HzfilterbasedonFFT_in
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% AprilTag_PickandPlace_P.undOrder25HzfilterbasedonFFT__k
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HILWrite_other_channels
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_stream_index
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.Video3DInitialize_active
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.Counter_InitialCount
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 59;
            section.data(59)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HomePosition_Value
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.PicturePosition_Value
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 3;

                    ;% AprilTag_PickandPlace_P.Constant_Value
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 6;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOTer
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 7;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOExi
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 8;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOSta
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 9;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOEnt
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 10;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOFin
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 11;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOFin
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 12;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOHig
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 16;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOLow
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 17;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOIni
                    section.data(12).logicalSrcIdx = 18;
                    section.data(12).dtTransOffset = 18;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOIni
                    section.data(13).logicalSrcIdx = 19;
                    section.data(13).dtTransOffset = 19;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOWat
                    section.data(14).logicalSrcIdx = 20;
                    section.data(14).dtTransOffset = 31;

                    ;% AprilTag_PickandPlace_P.StateSwitch_Value
                    section.data(15).logicalSrcIdx = 21;
                    section.data(15).dtTransOffset = 43;

                    ;% AprilTag_PickandPlace_P.TmpRTBAtMultiportSwitch1Inport1
                    section.data(16).logicalSrcIdx = 22;
                    section.data(16).dtTransOffset = 44;

                    ;% AprilTag_PickandPlace_P.ObjectPosition_Value
                    section.data(17).logicalSrcIdx = 23;
                    section.data(17).dtTransOffset = 45;

                    ;% AprilTag_PickandPlace_P.JointAnleforCameraPosition_Valu
                    section.data(18).logicalSrcIdx = 24;
                    section.data(18).dtTransOffset = 48;

                    ;% AprilTag_PickandPlace_P.ObjectOffset_Value
                    section.data(19).logicalSrcIdx = 25;
                    section.data(19).dtTransOffset = 52;

                    ;% AprilTag_PickandPlace_P.VerticalOffset_Value
                    section.data(20).logicalSrcIdx = 26;
                    section.data(20).dtTransOffset = 55;

                    ;% AprilTag_PickandPlace_P.GoalPosition_Value
                    section.data(21).logicalSrcIdx = 27;
                    section.data(21).dtTransOffset = 58;

                    ;% AprilTag_PickandPlace_P.PlacementOffset_Value
                    section.data(22).logicalSrcIdx = 28;
                    section.data(22).dtTransOffset = 61;

                    ;% AprilTag_PickandPlace_P.State3Constant_Value
                    section.data(23).logicalSrcIdx = 29;
                    section.data(23).dtTransOffset = 64;

                    ;% AprilTag_PickandPlace_P.Constant1_Value
                    section.data(24).logicalSrcIdx = 30;
                    section.data(24).dtTransOffset = 65;

                    ;% AprilTag_PickandPlace_P.TmpRTBAtRateLimiterOutport1_Ini
                    section.data(25).logicalSrcIdx = 31;
                    section.data(25).dtTransOffset = 69;

                    ;% AprilTag_PickandPlace_P.Integrator_IC
                    section.data(26).logicalSrcIdx = 32;
                    section.data(26).dtTransOffset = 70;

                    ;% AprilTag_PickandPlace_P.Integrator_UpperSat
                    section.data(27).logicalSrcIdx = 33;
                    section.data(27).dtTransOffset = 71;

                    ;% AprilTag_PickandPlace_P.Integrator_LowerSat
                    section.data(28).logicalSrcIdx = 34;
                    section.data(28).dtTransOffset = 72;

                    ;% AprilTag_PickandPlace_P.openposition_Value
                    section.data(29).logicalSrcIdx = 35;
                    section.data(29).dtTransOffset = 73;

                    ;% AprilTag_PickandPlace_P.Switch_Threshold
                    section.data(30).logicalSrcIdx = 36;
                    section.data(30).dtTransOffset = 74;

                    ;% AprilTag_PickandPlace_P.SmoothSignalGenerator_InitialPh
                    section.data(31).logicalSrcIdx = 37;
                    section.data(31).dtTransOffset = 75;

                    ;% AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude
                    section.data(32).logicalSrcIdx = 38;
                    section.data(32).dtTransOffset = 76;

                    ;% AprilTag_PickandPlace_P.SmoothSignalGenerator_Frequency
                    section.data(33).logicalSrcIdx = 39;
                    section.data(33).dtTransOffset = 77;

                    ;% AprilTag_PickandPlace_P.Bias_Bias
                    section.data(34).logicalSrcIdx = 40;
                    section.data(34).dtTransOffset = 78;

                    ;% AprilTag_PickandPlace_P.x0_Value
                    section.data(35).logicalSrcIdx = 41;
                    section.data(35).dtTransOffset = 79;

                    ;% AprilTag_PickandPlace_P.SoftGripCurrentA_Value
                    section.data(36).logicalSrcIdx = 42;
                    section.data(36).dtTransOffset = 80;

                    ;% AprilTag_PickandPlace_P.Constant_Value_e
                    section.data(37).logicalSrcIdx = 43;
                    section.data(37).dtTransOffset = 81;

                    ;% AprilTag_PickandPlace_P.Integrator2_IC
                    section.data(38).logicalSrcIdx = 44;
                    section.data(38).dtTransOffset = 82;

                    ;% AprilTag_PickandPlace_P.Gain2_Gain
                    section.data(39).logicalSrcIdx = 45;
                    section.data(39).dtTransOffset = 83;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Brightness
                    section.data(40).logicalSrcIdx = 46;
                    section.data(40).dtTransOffset = 84;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Contrast
                    section.data(41).logicalSrcIdx = 47;
                    section.data(41).dtTransOffset = 85;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Hue
                    section.data(42).logicalSrcIdx = 48;
                    section.data(42).dtTransOffset = 86;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Saturation
                    section.data(43).logicalSrcIdx = 49;
                    section.data(43).dtTransOffset = 87;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Sharpness
                    section.data(44).logicalSrcIdx = 50;
                    section.data(44).dtTransOffset = 88;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Gamma
                    section.data(45).logicalSrcIdx = 51;
                    section.data(45).dtTransOffset = 89;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_WhiteBalance
                    section.data(46).logicalSrcIdx = 52;
                    section.data(46).dtTransOffset = 90;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_BacklightCompens
                    section.data(47).logicalSrcIdx = 53;
                    section.data(47).dtTransOffset = 91;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Gain
                    section.data(48).logicalSrcIdx = 54;
                    section.data(48).dtTransOffset = 92;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Exposure
                    section.data(49).logicalSrcIdx = 55;
                    section.data(49).dtTransOffset = 93;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Emitter
                    section.data(50).logicalSrcIdx = 56;
                    section.data(50).dtTransOffset = 94;

                    ;% AprilTag_PickandPlace_P.Constant_Value_m
                    section.data(51).logicalSrcIdx = 57;
                    section.data(51).dtTransOffset = 95;

                    ;% AprilTag_PickandPlace_P.UnitDelay_InitialCondition
                    section.data(52).logicalSrcIdx = 58;
                    section.data(52).dtTransOffset = 96;

                    ;% AprilTag_PickandPlace_P.AddConstant_Bias
                    section.data(53).logicalSrcIdx = 59;
                    section.data(53).dtTransOffset = 97;

                    ;% AprilTag_PickandPlace_P.Delay_InitialCondition
                    section.data(54).logicalSrcIdx = 60;
                    section.data(54).dtTransOffset = 98;

                    ;% AprilTag_PickandPlace_P.GripperClose_Value
                    section.data(55).logicalSrcIdx = 61;
                    section.data(55).dtTransOffset = 99;

                    ;% AprilTag_PickandPlace_P.GripperOpen_Value
                    section.data(56).logicalSrcIdx = 62;
                    section.data(56).dtTransOffset = 100;

                    ;% AprilTag_PickandPlace_P.RateLimiter_RisingLim
                    section.data(57).logicalSrcIdx = 63;
                    section.data(57).dtTransOffset = 101;

                    ;% AprilTag_PickandPlace_P.RateLimiter_FallingLim
                    section.data(58).logicalSrcIdx = 64;
                    section.data(58).dtTransOffset = 102;

                    ;% AprilTag_PickandPlace_P.RateLimiter_IC
                    section.data(59).logicalSrcIdx = 65;
                    section.data(59).dtTransOffset = 103;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_CKCha
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOWat
                    section.data(2).logicalSrcIdx = 67;
                    section.data(2).dtTransOffset = 1;

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_Clock
                    section.data(3).logicalSrcIdx = 68;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AICha
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OOCha
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 5;

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_SamplesInBuffe
                    section.data(3).logicalSrcIdx = 71;
                    section.data(3).dtTransOffset = 18;

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_AnalogChannels
                    section.data(4).logicalSrcIdx = 72;
                    section.data(4).dtTransOffset = 19;

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_OtherChannels
                    section.data(5).logicalSrcIdx = 73;
                    section.data(5).dtTransOffset = 24;

                    ;% AprilTag_PickandPlace_P.VirtualQArmRGB_Preset
                    section.data(6).logicalSrcIdx = 74;
                    section.data(6).dtTransOffset = 44;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_Activ
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOTer
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 1;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOExi
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 2;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOTer
                    section.data(4).logicalSrcIdx = 78;
                    section.data(4).dtTransOffset = 3;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOExi
                    section.data(5).logicalSrcIdx = 79;
                    section.data(5).dtTransOffset = 4;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POTer
                    section.data(6).logicalSrcIdx = 80;
                    section.data(6).dtTransOffset = 5;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POExi
                    section.data(7).logicalSrcIdx = 81;
                    section.data(7).dtTransOffset = 6;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_CKPSt
                    section.data(8).logicalSrcIdx = 82;
                    section.data(8).dtTransOffset = 7;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_CKPEn
                    section.data(9).logicalSrcIdx = 83;
                    section.data(9).dtTransOffset = 8;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_CKSta
                    section.data(10).logicalSrcIdx = 84;
                    section.data(10).dtTransOffset = 9;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_CKEnt
                    section.data(11).logicalSrcIdx = 85;
                    section.data(11).dtTransOffset = 10;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AIPSt
                    section.data(12).logicalSrcIdx = 86;
                    section.data(12).dtTransOffset = 11;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AIPEn
                    section.data(13).logicalSrcIdx = 87;
                    section.data(13).dtTransOffset = 12;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOPSt
                    section.data(14).logicalSrcIdx = 88;
                    section.data(14).dtTransOffset = 13;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOPEn
                    section.data(15).logicalSrcIdx = 89;
                    section.data(15).dtTransOffset = 14;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOSta
                    section.data(16).logicalSrcIdx = 90;
                    section.data(16).dtTransOffset = 15;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AOEnt
                    section.data(17).logicalSrcIdx = 91;
                    section.data(17).dtTransOffset = 16;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_AORes
                    section.data(18).logicalSrcIdx = 92;
                    section.data(18).dtTransOffset = 17;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOPSt
                    section.data(19).logicalSrcIdx = 93;
                    section.data(19).dtTransOffset = 18;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOPEn
                    section.data(20).logicalSrcIdx = 94;
                    section.data(20).dtTransOffset = 19;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOSta
                    section.data(21).logicalSrcIdx = 95;
                    section.data(21).dtTransOffset = 20;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOEnt
                    section.data(22).logicalSrcIdx = 96;
                    section.data(22).dtTransOffset = 21;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DORes
                    section.data(23).logicalSrcIdx = 97;
                    section.data(23).dtTransOffset = 22;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_EIPSt
                    section.data(24).logicalSrcIdx = 98;
                    section.data(24).dtTransOffset = 23;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_EIPEn
                    section.data(25).logicalSrcIdx = 99;
                    section.data(25).dtTransOffset = 24;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_EISta
                    section.data(26).logicalSrcIdx = 100;
                    section.data(26).dtTransOffset = 25;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_EIEnt
                    section.data(27).logicalSrcIdx = 101;
                    section.data(27).dtTransOffset = 26;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POPSt
                    section.data(28).logicalSrcIdx = 102;
                    section.data(28).dtTransOffset = 27;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POPEn
                    section.data(29).logicalSrcIdx = 103;
                    section.data(29).dtTransOffset = 28;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POSta
                    section.data(30).logicalSrcIdx = 104;
                    section.data(30).dtTransOffset = 29;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_POEnt
                    section.data(31).logicalSrcIdx = 105;
                    section.data(31).dtTransOffset = 30;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_PORes
                    section.data(32).logicalSrcIdx = 106;
                    section.data(32).dtTransOffset = 31;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_OORes
                    section.data(33).logicalSrcIdx = 107;
                    section.data(33).dtTransOffset = 32;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOFin
                    section.data(34).logicalSrcIdx = 108;
                    section.data(34).dtTransOffset = 33;

                    ;% AprilTag_PickandPlace_P.HILInitializePositionMode_DOIni
                    section.data(35).logicalSrcIdx = 109;
                    section.data(35).dtTransOffset = 34;

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_Active
                    section.data(36).logicalSrcIdx = 110;
                    section.data(36).dtTransOffset = 35;

                    ;% AprilTag_PickandPlace_P.HILWrite_Active
                    section.data(37).logicalSrcIdx = 111;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_P.HILReadTimebase1_OverflowMode
                    section.data(1).logicalSrcIdx = 112;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (AprilTag_PickandPlace_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.VirtualQArmRGB_o2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 22;
            section.data(22)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.grippercurrent
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_B.HILReadTimebase1_o6
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% AprilTag_PickandPlace_B.HILReadTimebase1_o7
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% AprilTag_PickandPlace_B.HILReadTimebase1_o8
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% AprilTag_PickandPlace_B.HILReadTimebase1_o9
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% AprilTag_PickandPlace_B.TmpRTBAtMultiportSwitch1Inport1
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% AprilTag_PickandPlace_B.MultiportSwitch1
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% AprilTag_PickandPlace_B.MultiportSwitch
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 9;

                    ;% AprilTag_PickandPlace_B.TmpRTBAtRateLimiterOutport1
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 12;

                    ;% AprilTag_PickandPlace_B.gripposition
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 13;

                    ;% AprilTag_PickandPlace_B.x0
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 14;

                    ;% AprilTag_PickandPlace_B.Integrator1
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 15;

                    ;% AprilTag_PickandPlace_B.goalcurrent
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 16;

                    ;% AprilTag_PickandPlace_B.Product
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 17;

                    ;% AprilTag_PickandPlace_B.Product1
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 18;

                    ;% AprilTag_PickandPlace_B.Gain2
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 19;

                    ;% AprilTag_PickandPlace_B.VirtualQArmRGB_o3
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 20;

                    ;% AprilTag_PickandPlace_B.Sum
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 21;

                    ;% AprilTag_PickandPlace_B.AddConstant
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 22;

                    ;% AprilTag_PickandPlace_B.MultiportSwitch2
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 23;

                    ;% AprilTag_PickandPlace_B.trans
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 24;

                    ;% AprilTag_PickandPlace_B.theta
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.VirtualQArmRGB_o5
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.VirtualQArmRGB_o1
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.Equal
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_B.TmpRTBAtCounterInport2
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.sf_MATLABFunction3.position
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_B.sf_MATLABFunction2.position
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 13;
        sectIdxOffset = 7;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (AprilTag_PickandPlace_DW)
        ;%
            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_DW.Delay_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 15;

                    ;% AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 20;

                    ;% AprilTag_PickandPlace_DW.TmpRTBAtMultiportSwitch1Inport1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 40;

                    ;% AprilTag_PickandPlace_DW.TmpRTBAtRateLimiterOutport1_Buf
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 41;

                    ;% AprilTag_PickandPlace_DW.HILWrite_OtherBuffer
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 42;

                    ;% AprilTag_PickandPlace_DW.PrevY
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 55;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.Video3DInitialize_Video3D
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_DW.VirtualQArmRGB_Video3D
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.VirtualQArmRGB_Stream
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.HILInitializePositionMode_Card
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.HILReadTimebase1_Task
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.HILWrite_PWORK
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_DW.CurrentFilteration_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% AprilTag_PickandPlace_DW.GoalvsActualGripCurrent_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 3;

                    ;% AprilTag_PickandPlace_DW.Scope_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.VirtualQArmRGB_Intrinsics
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_DW.VirtualQArmRGB_Coefficients
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.HILInitializePositionMode_Clock
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.Counter_ClkEphState
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% AprilTag_PickandPlace_DW.Counter_RstEphState
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.VirtualQArmRGB_Model
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.Integrator1_IWORK
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% AprilTag_PickandPlace_DW.Counter_Count
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 871265169;
    targMap.checksum1 = 901344641;
    targMap.checksum2 = 3864447070;
    targMap.checksum3 = 1428478312;

