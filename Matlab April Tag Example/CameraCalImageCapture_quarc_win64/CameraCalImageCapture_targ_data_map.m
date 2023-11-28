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
        ;% Auto data (CameraCalImageCapture_P)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.ColorConstant_color
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.CompareToConstant_const
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% CameraCalImageCapture_P.isgreaterthan90degs_const
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% CameraCalImageCapture_P.undOrder25HzfilterbasedonFFT_in
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% CameraCalImageCapture_P.undOrder25HzfilterbasedonFFT__n
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.HILWrite_other_channels
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_stream_index
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.Video3DInitialize_active
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 46;
            section.data(46)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.SmoothSignalGenerator_InitialPh
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% CameraCalImageCapture_P.SmoothSignalGenerator_Frequency
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

                    ;% CameraCalImageCapture_P.Bias_Bias
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 3;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOTer
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 4;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOExi
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 5;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOSta
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 6;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOEnt
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 7;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOFin
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 8;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOFin
                    section.data(10).logicalSrcIdx = 18;
                    section.data(10).dtTransOffset = 9;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOHig
                    section.data(11).logicalSrcIdx = 19;
                    section.data(11).dtTransOffset = 13;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOLow
                    section.data(12).logicalSrcIdx = 20;
                    section.data(12).dtTransOffset = 14;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOIni
                    section.data(13).logicalSrcIdx = 21;
                    section.data(13).dtTransOffset = 15;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOIni
                    section.data(14).logicalSrcIdx = 22;
                    section.data(14).dtTransOffset = 16;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOWat
                    section.data(15).logicalSrcIdx = 23;
                    section.data(15).dtTransOffset = 20;

                    ;% CameraCalImageCapture_P.Constant1_Value
                    section.data(16).logicalSrcIdx = 24;
                    section.data(16).dtTransOffset = 24;

                    ;% CameraCalImageCapture_P.Constant6_Value
                    section.data(17).logicalSrcIdx = 25;
                    section.data(17).dtTransOffset = 28;

                    ;% CameraCalImageCapture_P.DefaultCmd_Value
                    section.data(18).logicalSrcIdx = 26;
                    section.data(18).dtTransOffset = 29;

                    ;% CameraCalImageCapture_P.RateLimiter_RisingLim
                    section.data(19).logicalSrcIdx = 27;
                    section.data(19).dtTransOffset = 33;

                    ;% CameraCalImageCapture_P.RateLimiter_FallingLim
                    section.data(20).logicalSrcIdx = 28;
                    section.data(20).dtTransOffset = 34;

                    ;% CameraCalImageCapture_P.RateLimiter_IC
                    section.data(21).logicalSrcIdx = 29;
                    section.data(21).dtTransOffset = 35;

                    ;% CameraCalImageCapture_P.Integrator_IC
                    section.data(22).logicalSrcIdx = 30;
                    section.data(22).dtTransOffset = 36;

                    ;% CameraCalImageCapture_P.Integrator_UpperSat
                    section.data(23).logicalSrcIdx = 31;
                    section.data(23).dtTransOffset = 37;

                    ;% CameraCalImageCapture_P.Integrator_LowerSat
                    section.data(24).logicalSrcIdx = 32;
                    section.data(24).dtTransOffset = 38;

                    ;% CameraCalImageCapture_P.openposition_Value
                    section.data(25).logicalSrcIdx = 33;
                    section.data(25).dtTransOffset = 39;

                    ;% CameraCalImageCapture_P.Switch_Threshold
                    section.data(26).logicalSrcIdx = 34;
                    section.data(26).dtTransOffset = 40;

                    ;% CameraCalImageCapture_P.x0_Value
                    section.data(27).logicalSrcIdx = 35;
                    section.data(27).dtTransOffset = 41;

                    ;% CameraCalImageCapture_P.SoftGripCurrentA_Value
                    section.data(28).logicalSrcIdx = 36;
                    section.data(28).dtTransOffset = 42;

                    ;% CameraCalImageCapture_P.Constant_Value
                    section.data(29).logicalSrcIdx = 37;
                    section.data(29).dtTransOffset = 43;

                    ;% CameraCalImageCapture_P.Integrator2_IC
                    section.data(30).logicalSrcIdx = 38;
                    section.data(30).dtTransOffset = 44;

                    ;% CameraCalImageCapture_P.Gain2_Gain
                    section.data(31).logicalSrcIdx = 39;
                    section.data(31).dtTransOffset = 45;

                    ;% CameraCalImageCapture_P.Constant6_Value_f
                    section.data(32).logicalSrcIdx = 40;
                    section.data(32).dtTransOffset = 46;

                    ;% CameraCalImageCapture_P.Gain_Gain
                    section.data(33).logicalSrcIdx = 41;
                    section.data(33).dtTransOffset = 50;

                    ;% CameraCalImageCapture_P.Saturation_UpperSat
                    section.data(34).logicalSrcIdx = 42;
                    section.data(34).dtTransOffset = 51;

                    ;% CameraCalImageCapture_P.Saturation_LowerSat
                    section.data(35).logicalSrcIdx = 43;
                    section.data(35).dtTransOffset = 52;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Brightness
                    section.data(36).logicalSrcIdx = 44;
                    section.data(36).dtTransOffset = 53;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Contrast
                    section.data(37).logicalSrcIdx = 45;
                    section.data(37).dtTransOffset = 54;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Hue
                    section.data(38).logicalSrcIdx = 46;
                    section.data(38).dtTransOffset = 55;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Saturation
                    section.data(39).logicalSrcIdx = 47;
                    section.data(39).dtTransOffset = 56;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Sharpness
                    section.data(40).logicalSrcIdx = 48;
                    section.data(40).dtTransOffset = 57;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Gamma
                    section.data(41).logicalSrcIdx = 49;
                    section.data(41).dtTransOffset = 58;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_WhiteBalance
                    section.data(42).logicalSrcIdx = 50;
                    section.data(42).dtTransOffset = 59;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_BacklightCompens
                    section.data(43).logicalSrcIdx = 51;
                    section.data(43).dtTransOffset = 60;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Gain
                    section.data(44).logicalSrcIdx = 52;
                    section.data(44).dtTransOffset = 61;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Exposure
                    section.data(45).logicalSrcIdx = 53;
                    section.data(45).dtTransOffset = 62;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Emitter
                    section.data(46).logicalSrcIdx = 54;
                    section.data(46).dtTransOffset = 63;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_CKCha
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOWat
                    section.data(2).logicalSrcIdx = 56;
                    section.data(2).dtTransOffset = 1;

                    ;% CameraCalImageCapture_P.HILReadTimebase1_Clock
                    section.data(3).logicalSrcIdx = 57;
                    section.data(3).dtTransOffset = 2;

                    ;% CameraCalImageCapture_P.HILSetProperty_PropertyCodes
                    section.data(4).logicalSrcIdx = 58;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AICha
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OOCha
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 5;

                    ;% CameraCalImageCapture_P.HILReadTimebase1_SamplesInBuffe
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 9;

                    ;% CameraCalImageCapture_P.HILReadTimebase1_AnalogChannels
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 10;

                    ;% CameraCalImageCapture_P.HILReadTimebase1_OtherChannels
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 15;

                    ;% CameraCalImageCapture_P.VirtualQArmRGB_Preset
                    section.data(6).logicalSrcIdx = 64;
                    section.data(6).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.HILWrite_Active
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_P.Constant_Value_f
                    section.data(2).logicalSrcIdx = 66;
                    section.data(2).dtTransOffset = 1;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_Activ
                    section.data(3).logicalSrcIdx = 67;
                    section.data(3).dtTransOffset = 2;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOTer
                    section.data(4).logicalSrcIdx = 68;
                    section.data(4).dtTransOffset = 3;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOExi
                    section.data(5).logicalSrcIdx = 69;
                    section.data(5).dtTransOffset = 4;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOTer
                    section.data(6).logicalSrcIdx = 70;
                    section.data(6).dtTransOffset = 5;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOExi
                    section.data(7).logicalSrcIdx = 71;
                    section.data(7).dtTransOffset = 6;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POTer
                    section.data(8).logicalSrcIdx = 72;
                    section.data(8).dtTransOffset = 7;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POExi
                    section.data(9).logicalSrcIdx = 73;
                    section.data(9).dtTransOffset = 8;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_CKPSt
                    section.data(10).logicalSrcIdx = 74;
                    section.data(10).dtTransOffset = 9;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_CKPEn
                    section.data(11).logicalSrcIdx = 75;
                    section.data(11).dtTransOffset = 10;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_CKSta
                    section.data(12).logicalSrcIdx = 76;
                    section.data(12).dtTransOffset = 11;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_CKEnt
                    section.data(13).logicalSrcIdx = 77;
                    section.data(13).dtTransOffset = 12;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AIPSt
                    section.data(14).logicalSrcIdx = 78;
                    section.data(14).dtTransOffset = 13;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AIPEn
                    section.data(15).logicalSrcIdx = 79;
                    section.data(15).dtTransOffset = 14;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOPSt
                    section.data(16).logicalSrcIdx = 80;
                    section.data(16).dtTransOffset = 15;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOPEn
                    section.data(17).logicalSrcIdx = 81;
                    section.data(17).dtTransOffset = 16;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOSta
                    section.data(18).logicalSrcIdx = 82;
                    section.data(18).dtTransOffset = 17;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AOEnt
                    section.data(19).logicalSrcIdx = 83;
                    section.data(19).dtTransOffset = 18;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_AORes
                    section.data(20).logicalSrcIdx = 84;
                    section.data(20).dtTransOffset = 19;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOPSt
                    section.data(21).logicalSrcIdx = 85;
                    section.data(21).dtTransOffset = 20;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOPEn
                    section.data(22).logicalSrcIdx = 86;
                    section.data(22).dtTransOffset = 21;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOSta
                    section.data(23).logicalSrcIdx = 87;
                    section.data(23).dtTransOffset = 22;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOEnt
                    section.data(24).logicalSrcIdx = 88;
                    section.data(24).dtTransOffset = 23;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DORes
                    section.data(25).logicalSrcIdx = 89;
                    section.data(25).dtTransOffset = 24;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_EIPSt
                    section.data(26).logicalSrcIdx = 90;
                    section.data(26).dtTransOffset = 25;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_EIPEn
                    section.data(27).logicalSrcIdx = 91;
                    section.data(27).dtTransOffset = 26;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_EISta
                    section.data(28).logicalSrcIdx = 92;
                    section.data(28).dtTransOffset = 27;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_EIEnt
                    section.data(29).logicalSrcIdx = 93;
                    section.data(29).dtTransOffset = 28;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POPSt
                    section.data(30).logicalSrcIdx = 94;
                    section.data(30).dtTransOffset = 29;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POPEn
                    section.data(31).logicalSrcIdx = 95;
                    section.data(31).dtTransOffset = 30;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POSta
                    section.data(32).logicalSrcIdx = 96;
                    section.data(32).dtTransOffset = 31;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_POEnt
                    section.data(33).logicalSrcIdx = 97;
                    section.data(33).dtTransOffset = 32;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_PORes
                    section.data(34).logicalSrcIdx = 98;
                    section.data(34).dtTransOffset = 33;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_OORes
                    section.data(35).logicalSrcIdx = 99;
                    section.data(35).dtTransOffset = 34;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOFin
                    section.data(36).logicalSrcIdx = 100;
                    section.data(36).dtTransOffset = 35;

                    ;% CameraCalImageCapture_P.HILInitializePositionMode_DOIni
                    section.data(37).logicalSrcIdx = 101;
                    section.data(37).dtTransOffset = 36;

                    ;% CameraCalImageCapture_P.HILReadTimebase1_Active
                    section.data(38).logicalSrcIdx = 102;
                    section.data(38).dtTransOffset = 37;

                    ;% CameraCalImageCapture_P.HILSetProperty_Active
                    section.data(39).logicalSrcIdx = 103;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_P.HILReadTimebase1_OverflowMode
                    section.data(1).logicalSrcIdx = 104;
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
        nTotSects     = 4;
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
        ;% Auto data (CameraCalImageCapture_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_B.VirtualQArmRGB_o2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% CameraCalImageCapture_B.grippercurrent
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_B.RateLimiter
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% CameraCalImageCapture_B.gripposition
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% CameraCalImageCapture_B.x0
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% CameraCalImageCapture_B.Integrator1
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% CameraCalImageCapture_B.goalcurrent
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% CameraCalImageCapture_B.Product
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% CameraCalImageCapture_B.Product1
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% CameraCalImageCapture_B.Gain2
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% CameraCalImageCapture_B.VirtualQArmRGB_o3
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% CameraCalImageCapture_B.VirtualQArmRGB_o1
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_B.outputImage
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 921600;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_B.foranyofthejoints
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
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
        nTotSects     = 14;
        sectIdxOffset = 4;

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
        ;% Auto data (CameraCalImageCapture_DW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 5;

                    ;% CameraCalImageCapture_DW.PrevY
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 25;

                    ;% CameraCalImageCapture_DW.HILWrite_OtherBuffer
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 26;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.Video3DInitialize_Video3D
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_DW.VirtualQArmRGB_Video3D
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.VirtualQArmRGB_Stream
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.HILInitializePositionMode_Card
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.HILReadTimebase1_Task
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.CurrentFilteration_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_DW.GoalvsActualGripCurrent_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 2;

                    ;% CameraCalImageCapture_DW.HILSetProperty_PWORK
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 4;

                    ;% CameraCalImageCapture_DW.HILWrite_PWORK
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.VirtualQArmRGB_Intrinsics
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% CameraCalImageCapture_DW.VirtualQArmRGB_Coefficients
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.HILInitializePositionMode_Clock
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.VirtualQArmRGB_Model
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.HILSetProperty_DoubleCodes
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.Integrator1_IWORK
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.Subsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% CameraCalImageCapture_DW.Subsystem_MODE
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
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


    targMap.checksum0 = 4016575198;
    targMap.checksum1 = 1883061939;
    targMap.checksum2 = 1958159336;
    targMap.checksum3 = 3875328894;

