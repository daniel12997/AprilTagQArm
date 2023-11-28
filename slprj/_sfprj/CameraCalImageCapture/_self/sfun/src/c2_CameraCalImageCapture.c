/* Include files */

#include "CameraCalImageCapture_sfun.h"
#include "c2_CameraCalImageCapture.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c2_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c2_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c2_c_emlrtMCI = { 624,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pName */
};

static emlrtMCInfo c2_d_emlrtMCI = { 634,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pName */
};

static emlrtMCInfo c2_e_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c2_f_emlrtMCI = { 242,/* lineNo */
  43,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtMCInfo c2_g_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c2_h_emlrtMCI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pName */
};

static emlrtMCInfo c2_i_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c2_j_emlrtMCI = { 123,/* lineNo */
  21,                                  /* colNo */
  "rigidtform3dImpl",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pName */
};

static emlrtMCInfo c2_k_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_l_emlrtMCI = { 448,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_m_emlrtMCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_n_emlrtMCI = { 184,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_o_emlrtMCI = { 217,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_p_emlrtMCI = { 238,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_q_emlrtMCI = { 181,/* lineNo */
  21,                                  /* colNo */
  "MatrixTransformation",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pName */
};

static emlrtMCInfo c2_r_emlrtMCI = { 190,/* lineNo */
  21,                                  /* colNo */
  "MatrixTransformation",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 8,  /* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#CameraCalImageCapture:92"          /* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 10,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#CameraCalImageCapture:92"          /* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 5,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#CameraCalImageCapture:92"          /* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 26,/* lineNo */
  "cameraIntrinsics",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsics.m"/* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 25,/* lineNo */
  "cameraIntrinsics",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsics.m"/* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 82,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 99,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 100,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 193,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 232,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 235,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 151,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 162,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_o_emlrtRSI = { 136,/* lineNo */
  "cameraIntrinsicsImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pathName */
};

static emlrtRSInfo c2_p_emlrtRSI = { 210,/* lineNo */
  "cameraParameters",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\cameraParameters.m"/* pathName */
};

static emlrtRSInfo c2_q_emlrtRSI = { 211,/* lineNo */
  "cameraParameters",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\cameraParameters.m"/* pathName */
};

static emlrtRSInfo c2_r_emlrtRSI = { 9,/* lineNo */
  "CustomDisplay",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\CustomDisplay.m"/* pathName */
};

static emlrtRSInfo c2_s_emlrtRSI = { 245,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_t_emlrtRSI = { 241,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_u_emlrtRSI = { 247,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_v_emlrtRSI = { 266,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_w_emlrtRSI = { 364,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_x_emlrtRSI = { 384,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_y_emlrtRSI = { 1176,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_ab_emlrtRSI = { 1181,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_bb_emlrtRSI = { 619,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_cb_emlrtRSI = { 629,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_db_emlrtRSI = { 6,/* lineNo */
  "HandleCodegen",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+enforcescalar\\HandleCodegen.m"/* pathName */
};

static emlrtRSInfo c2_eb_emlrtRSI = { 6,/* lineNo */
  "HandleBase",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+enforcescalar\\HandleBase.m"/* pathName */
};

static emlrtRSInfo c2_fb_emlrtRSI = { 287,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_gb_emlrtRSI = { 289,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_hb_emlrtRSI = { 292,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_ib_emlrtRSI = { 295,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_jb_emlrtRSI = { 296,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_kb_emlrtRSI = { 313,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_lb_emlrtRSI = { 640,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_mb_emlrtRSI = { 650,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_nb_emlrtRSI = { 660,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_ob_emlrtRSI = { 472,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_pb_emlrtRSI = { 715,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo c2_qb_emlrtRSI = { 43,/* lineNo */
  "ImageTransformer",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pathName */
};

static emlrtRSInfo c2_rb_emlrtRSI = { 305,/* lineNo */
  "cameraIntrinsics",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsics.m"/* pathName */
};

static emlrtRSInfo c2_sb_emlrtRSI = { 34,/* lineNo */
  "cameraIntrinsicsArray",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsicsArray.m"/* pathName */
};

static emlrtRSInfo c2_tb_emlrtRSI = { 196,/* lineNo */
  "strjoin",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\strjoin.m"/* pathName */
};

static emlrtRSInfo c2_ub_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c2_vb_emlrtRSI = { 10,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_wb_emlrtRSI = { 38,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_xb_emlrtRSI = { 91,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_yb_emlrtRSI = { 241,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_ac_emlrtRSI = { 36,/* lineNo */
  "strjoin",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\strjoin.m"/* pathName */
};

static emlrtRSInfo c2_bc_emlrtRSI = { 80,/* lineNo */
  "strjoin",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\strjoin.m"/* pathName */
};

static emlrtRSInfo c2_cc_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c2_dc_emlrtRSI = { 135,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_ec_emlrtRSI = { 170,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_fc_emlrtRSI = { 173,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_gc_emlrtRSI = { 182,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_hc_emlrtRSI = { 181,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_ic_emlrtRSI = { 183,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_jc_emlrtRSI = { 140,/* lineNo */
  "readAprilTagBuildable",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pathName */
};

static emlrtRSInfo c2_kc_emlrtRSI = { 164,/* lineNo */
  "readAprilTagBuildable",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pathName */
};

static emlrtRSInfo c2_lc_emlrtRSI = { 10,/* lineNo */
  "constrainToRotationMatrix3D",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\constrainToRotationMatrix3D.m"/* pathName */
};

static emlrtRSInfo c2_mc_emlrtRSI = { 17,/* lineNo */
  "constrainToRotationMatrix3D",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\constrainToRotationMatrix3D.m"/* pathName */
};

static emlrtRSInfo c2_nc_emlrtRSI = { 35,/* lineNo */
  "constrainToRotationMatrix3D",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\constrainToRotationMatrix3D.m"/* pathName */
};

static emlrtRSInfo c2_oc_emlrtRSI = { 14,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo c2_pc_emlrtRSI = { 36,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo c2_qc_emlrtRSI = { 42,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo c2_rc_emlrtRSI = { 29,/* lineNo */
  "anyNonFinite",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite.m"/* pathName */
};

static emlrtRSInfo c2_sc_emlrtRSI = { 44,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c2_tc_emlrtRSI = { 103,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c2_uc_emlrtRSI = { 52,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c2_vc_emlrtRSI = { 107,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c2_wc_emlrtRSI = { 34,/* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo c2_xc_emlrtRSI = { 428,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_yc_emlrtRSI = { 407,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_ad_emlrtRSI = { 394,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_bd_emlrtRSI = { 391,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_cd_emlrtRSI = { 380,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_dd_emlrtRSI = { 353,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_ed_emlrtRSI = { 351,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_fd_emlrtRSI = { 334,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_gd_emlrtRSI = { 251,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_hd_emlrtRSI = { 240,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_id_emlrtRSI = { 215,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_jd_emlrtRSI = { 194,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_kd_emlrtRSI = { 184,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_ld_emlrtRSI = { 120,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_md_emlrtRSI = { 114,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_nd_emlrtRSI = { 94,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_od_emlrtRSI = { 82,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_pd_emlrtRSI = { 77,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c2_qd_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c2_rd_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c2_sd_emlrtRSI = { 21,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c2_td_emlrtRSI = { 23,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c2_ud_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo c2_vd_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo c2_wd_emlrtRSI = { 32,/* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

static emlrtRSInfo c2_xd_emlrtRSI = { 35,/* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdot.m"/* pathName */
};

static emlrtRSInfo c2_yd_emlrtRSI = { 15,/* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

static emlrtRSInfo c2_ae_emlrtRSI = { 42,/* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

static emlrtRSInfo c2_be_emlrtRSI = { 23,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c2_ce_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c2_de_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c2_ee_emlrtRSI = { 21,/* lineNo */
  "det",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\det.m"/* pathName */
};

static emlrtRSInfo c2_fe_emlrtRSI = { 30,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c2_ge_emlrtRSI = { 50,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c2_he_emlrtRSI = { 58,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c2_ie_emlrtRSI = { 45,/* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo c2_je_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c2_ke_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo c2_le_emlrtRSI = { 54,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c2_me_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c2_ne_emlrtRSI = { 119,/* lineNo */
  "norm",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m"/* pathName */
};

static emlrtRSInfo c2_oe_emlrtRSI = { 156,/* lineNo */
  "norm",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m"/* pathName */
};

static emlrtRSInfo c2_pe_emlrtRSI = { 28,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c2_qe_emlrtRSI = { 11,/* lineNo */
  "rank",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

static emlrtRSInfo c2_re_emlrtRSI = { 20,/* lineNo */
  "rank",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

static emlrtRSInfo c2_se_emlrtRSI = { 18,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo c2_te_emlrtRSI = { 272,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_ue_emlrtRSI = { 275,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_ve_emlrtRSI = { 50,/* lineNo */
  "rigidtform3d",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\rigidtform3d.m"/* pathName */
};

static emlrtRSInfo c2_we_emlrtRSI = { 51,/* lineNo */
  "rigidtform3d",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\rigidtform3d.m"/* pathName */
};

static emlrtRSInfo c2_xe_emlrtRSI = { 61,/* lineNo */
  "rigidtform3dImpl",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pathName */
};

static emlrtRSInfo c2_ye_emlrtRSI = { 117,/* lineNo */
  "rigidtform3dImpl",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pathName */
};

static emlrtRSInfo c2_af_emlrtRSI = { 13,/* lineNo */
  "checkRotationMatrix3D",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\checkRotationMatrix3D.m"/* pathName */
};

static emlrtRSInfo c2_bf_emlrtRSI = { 14,/* lineNo */
  "checkRotationMatrix3D",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\checkRotationMatrix3D.m"/* pathName */
};

static emlrtRSInfo c2_cf_emlrtRSI = { 20,/* lineNo */
  "matricesNearlyEqual",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\matricesNearlyEqual.m"/* pathName */
};

static emlrtRSInfo c2_df_emlrtRSI = { 30,/* lineNo */
  "matricesNearlyEqual",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\matricesNearlyEqual.m"/* pathName */
};

static emlrtRSInfo c2_ef_emlrtRSI = { 53,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_ff_emlrtRSI = { 54,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_gf_emlrtRSI = { 439,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_hf_emlrtRSI = { 441,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_if_emlrtRSI = { 461,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_jf_emlrtRSI = { 258,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_kf_emlrtRSI = { 132,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_lf_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_mf_emlrtRSI = { 17,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_nf_emlrtRSI = { 167,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_of_emlrtRSI = { 169,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_pf_emlrtRSI = { 172,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_qf_emlrtRSI = { 15,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_rf_emlrtRSI = { 220,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_sf_emlrtRSI = { 223,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_tf_emlrtRSI = { 230,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_uf_emlrtRSI = { 232,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_vf_emlrtRSI = { 242,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_wf_emlrtRSI = { 70,/* lineNo */
  "OneDimArrayBehaviorTransform",      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pathName */
};

static emlrtRSInfo c2_xf_emlrtRSI = { 210,/* lineNo */
  "MatrixTransformation",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pathName */
};

static emlrtRSInfo c2_yf_emlrtRSI = { 170,/* lineNo */
  "MatrixTransformation",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pathName */
};

static emlrtRSInfo c2_ag_emlrtRSI = { 175,/* lineNo */
  "MatrixTransformation",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pathName */
};

static emlrtRSInfo c2_bg_emlrtRSI = { 185,/* lineNo */
  "MatrixTransformation",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pathName */
};

static emlrtRSInfo c2_cg_emlrtRSI = { 195,/* lineNo */
  "MatrixTransformation",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\MatrixTransformation.m"/* pathName */
};

static emlrtRSInfo c2_dg_emlrtRSI = { 165,/* lineNo */
  "rigidtform3dImpl",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pathName */
};

static emlrtRSInfo c2_eg_emlrtRSI = { 202,/* lineNo */
  "rigidtform3dImpl",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pathName */
};

static emlrtRSInfo c2_fg_emlrtRSI = { 19,/* lineNo */
  "isTransformationMatrixSingular",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\isTransformationMatrixSingular.m"/* pathName */
};

static emlrtRSInfo c2_gg_emlrtRSI = { 21,/* lineNo */
  "isTransformationMatrixSingular",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\isTransformationMatrixSingular.m"/* pathName */
};

static emlrtRSInfo c2_hg_emlrtRSI = { 183,/* lineNo */
  "rigidtform3dImpl",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+geotrans\\+internal\\rigidtform3dImpl.m"/* pathName */
};

static emlrtRTEInfo c2_emlrtRTEI = { 5,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function",                   /* fName */
  "#CameraCalImageCapture:92"          /* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 100,/* lineNo */
  37,                                  /* colNo */
  "cameraIntrinsicsImpl",              /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\cameraIntrinsicsImpl.m"/* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 305,/* lineNo */
  20,                                  /* colNo */
  "cameraIntrinsics",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsics.m"/* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 308,/* lineNo */
  13,                                  /* colNo */
  "cameraIntrinsics",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+codegen\\cameraIntrinsics.m"/* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 8,/* lineNo */
  19,                                  /* colNo */
  "MATLAB Function",                   /* fName */
  "#CameraCalImageCapture:92"          /* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 10,/* lineNo */
  17,                                  /* colNo */
  "MATLAB Function",                   /* fName */
  "#CameraCalImageCapture:92"          /* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 45,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 46,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 49,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\ImageTransformer.m"/* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 168,/* lineNo */
  5,                                   /* colNo */
  "strjoin",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\strjoin.m"/* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "blanks",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\blanks.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 241,/* lineNo */
  5,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 59,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 126,/* lineNo */
  67,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 133,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 134,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 135,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 137,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 138,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 140,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 135,/* lineNo */
  5,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 158,/* lineNo */
  41,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 166,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 167,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 51,/* lineNo */
  20,                                  /* colNo */
  "rigidtform3d",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\rigidtform3d.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 54,/* lineNo */
  13,                                  /* colNo */
  "rigidtform3d",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\rigidtform3d.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 181,/* lineNo */
  4,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 176,/* lineNo */
  13,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 181,/* lineNo */
  1,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 182,/* lineNo */
  9,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 183,/* lineNo */
  16,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 185,/* lineNo */
  1,                                   /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 173,/* lineNo */
  13,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 110,/* lineNo */
  41,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 94,/* lineNo */
  57,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 104,/* lineNo */
  41,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 99,/* lineNo */
  36,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 106,/* lineNo */
  17,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 135,/* lineNo */
  15,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 106,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 108,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 173,/* lineNo */
  32,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 94,/* lineNo */
  21,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 126,/* lineNo */
  44,                                  /* colNo */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 165,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ac_emlrtRTEI = { 257,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_bc_emlrtRTEI = { 29,/* lineNo */
  26,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_cc_emlrtRTEI = { 61,/* lineNo */
  32,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_dc_emlrtRTEI = { 64,/* lineNo */
  13,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_ec_emlrtRTEI = { 70,/* lineNo */
  27,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pName */
};

static emlrtRTEInfo c2_fc_emlrtRTEI = { 53,/* lineNo */
  25,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_gc_emlrtRTEI = { 451,/* lineNo */
  20,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_hc_emlrtRTEI = { 437,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ic_emlrtRTEI = { 1,/* lineNo */
  29,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_jc_emlrtRTEI = { 15,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_kc_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_lc_emlrtRTEI = { 221,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_mc_emlrtRTEI = { 246,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_nc_emlrtRTEI = { 224,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_oc_emlrtRTEI = { 228,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtBCInfo c2_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  84,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_emlrtDCI = { 166,/* lineNo */
  40,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  166,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_b_emlrtDCI = { 166,/* lineNo */
  48,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  166,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_c_emlrtDCI = { 133,/* lineNo */
  34,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c2_d_emlrtDCI = { 137,/* lineNo */
  47,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c2_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_e_emlrtDCI = { 133,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c2_f_emlrtDCI = { 137,/* lineNo */
  21,                                  /* colNo */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c2_g_emlrtDCI = { 12,/* lineNo */
  20,                                  /* colNo */
  "blanks",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\strfun\\blanks.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c2_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "readAprilTag",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  166,                                 /* lineNo */
  76,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_h_emlrtDCI = { 94,/* lineNo */
  57,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_i_emlrtDCI = { 110,/* lineNo */
  31,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_j_emlrtDCI = { 104,/* lineNo */
  31,                                  /* colNo */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "OneDimArrayBehaviorTransform",      /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "readAprilTagBuildable",             /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\+vision\\+internal\\+buildable\\readAprilTagBuildable.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_k_emlrtDCI = { 451,/* lineNo */
  58,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c2_l_emlrtDCI = { 218,/* lineNo */
  35,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c2_m_emlrtDCI = { 239,/* lineNo */
  35,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRSInfo c2_ig_emlrtRSI = { 176,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_jg_emlrtRSI = { 185,/* lineNo */
  "readAprilTag",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\vision\\vision\\readAprilTag.m"/* pathName */
};

static emlrtRSInfo c2_kg_emlrtRSI = { 1,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_lg_emlrtRSI = { 64,/* lineNo */
  "OneDimArrayBehaviorTransform",      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pathName */
};

static emlrtRSInfo c2_mg_emlrtRSI = { 61,/* lineNo */
  "OneDimArrayBehaviorTransform",      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\images\\images\\+images\\+internal\\+coder\\OneDimArrayBehaviorTransform.m"/* pathName */
};

static emlrtRSInfo c2_ng_emlrtRSI = { 257,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static real_T c2_dv[4] = { 0.0, 0.0, 0.0, 1.0 };

static char_T c2_cv[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i',
  'n', 'i', 't', 'e' };

static real_T c2_dv1[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

static char_T c2_cv1[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 'm',
  'e', 'r', 'a', 'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ':', 'e', 'x',
  'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

static char_T c2_cv2[37] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o',
  't', 'r', 'a', 'n', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'R', 'o', 't',
  'a', 't', 'i', 'o', 'n', 'M', 'a', 't', 'r', 'i', 'x' };

static char_T c2_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c2_cv4[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
  's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h' };

static char_T c2_cv5[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g',
  'e', 'n', 'c', 'e' };

/* Function Declarations */
static void initialize_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void initialize_params_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void mdl_start_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void mdl_terminate_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void enable_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void disable_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void sf_gateway_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void ext_mode_exec_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void c2_update_jit_animation_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void c2_do_animation_call_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void set_sim_state_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const mxArray *c2_st);
static void initSimStructsc2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static c2_cameraParameters *c2_cameraIntrinsicsImpl_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cameraIntrinsics *c2_this, c2_cameraParameters *c2_iobj_0);
static void c2_validateattributes(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real32_T c2_a[9]);
static boolean_T c2_any(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  real32_T c2_x[3]);
static void c2_CameraParametersImpl_checkImageSize
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, real_T c2_imageSize[2]);
static void c2_readAprilTag(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, uint8_T c2_c_I[307200],
  c2_cameraIntrinsics *c2_varargin_2, c2_emxArray_real_T *c2_varargout_1,
  c2_emxArray_real_T *c2_varargout_2, c2_rigidtform3d *c2_varargout_3);
static void c2_check_forloop_overflow_error
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp);
static void c2_readAprilTagIDPose(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, uint8_T c2_c_I[307200],
  c2_cameraIntrinsics *c2_intrinsics, c2_emxArray_real_T *c2_id,
  c2_emxArray_real_T *c2_loc, c2_rigidtform3d *c2_pose);
static void c2_constrainToRotationMatrix3D
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, real_T c2_R[9], real_T c2_Rc[9]);
static boolean_T c2_flatVectorAllOrAny(SFc2_CameraCalImageCaptureInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, real_T c2_x_data[], int32_T c2_x_size
  [2]);
static void c2_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_A[9], real_T c2_U[9],
                      real_T c2_S[3], real_T c2_V[9]);
static real_T c2_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[9], int32_T c2_ix0);
static real_T c2_sqrt(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_x);
static void c2_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T
                     c2_x[9], int32_T c2_ix0, real_T c2_b_x[9]);
static real_T c2_xdotc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[9], int32_T c2_ix0, real_T
  c2_y[9], int32_T c2_iy0);
static void c2_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[9],
                     int32_T c2_iy0, real_T c2_b_y[9]);
static real_T c2_b_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_x[3], int32_T c2_ix0);
static void c2_b_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T
  c2_b_x[3]);
static void c2_b_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T c2_y[3],
  int32_T c2_iy0, real_T c2_b_y[3]);
static void c2_c_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T c2_y[9],
  int32_T c2_iy0, real_T c2_b_y[9]);
static void c2_c_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T
  c2_b_x[9]);
static void c2_xrot(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                    real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c,
                    real_T c2_s, real_T c2_b_x[9]);
static void c2_xswap(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T
                     c2_b_x[9]);
static real_T c2_det(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     const emlrtStack *c2_sp, real_T c2_x[9]);
static real_T c2_norm(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_x[9]);
static void c2_b_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_A[9], real_T c2_S[3]);
static real_T c2_b_norm(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_x[16]);
static void c2_c_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_A[16], real_T c2_S[4]);
static real_T c2_c_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0);
static void c2_d_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T
  c2_ix0, real_T c2_b_x[16]);
static real_T c2_b_xdotc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, real_T
  c2_y[16], int32_T c2_iy0);
static void c2_d_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0,
  real_T c2_b_y[16]);
static real_T c2_d_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0);
static void c2_e_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T
  c2_ix0, real_T c2_b_x[4]);
static void c2_e_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[4],
  int32_T c2_iy0, real_T c2_b_y[4]);
static void c2_f_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_y[16],
  int32_T c2_iy0, real_T c2_b_y[16]);
static void c2_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_x,
  c2_emxArray_int32_T *c2_idx, c2_emxArray_real_T *c2_b_x);
static void c2_make_bitarray(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_n, c2_emxArray_int32_T
  *c2_idx, c2_emxArray_boolean_T *c2_b);
static int32_T c2_num_true(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_b);
static void c2_b_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_x,
  c2_emxArray_int32_T *c2_idx, c2_emxArray_cell_wrap_22 *c2_b_x);
static void c2_OneDimArrayBehaviorTransform_parenReference
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_rigidtform3d *c2_this, c2_rigidtform3d *c2_this1);
static const mxArray *c2_emlrt_marshallOut
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const char_T c2_u[30]);
static void c2_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_b_T, const char_T *c2_identifier, real_T
  c2_y[16]);
static void c2_b_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static uint8_T c2_c_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CameraCalImageCapture, const
  char_T *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_slStringInitializeDynamicBuffers
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance);
static void c2_chart_data_browse_helper(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static void c2_b_sqrt(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T *c2_x);
static void c2_f_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T
  c2_ix0);
static void c2_g_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[9], int32_T c2_iy0);
static void c2_g_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[3], int32_T c2_ix0);
static void c2_h_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T c2_y[3],
  int32_T c2_iy0);
static void c2_i_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T c2_y[9],
  int32_T c2_iy0);
static void c2_h_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[9], int32_T c2_ix0);
static void c2_b_xrot(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T
                      c2_c, real_T c2_s);
static void c2_b_xswap(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0);
static void c2_i_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T
  c2_ix0);
static void c2_j_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0);
static void c2_j_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T
  c2_ix0);
static void c2_k_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[4],
  int32_T c2_iy0);
static void c2_l_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_y[16],
  int32_T c2_iy0);
static void c2_c_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_x,
  c2_emxArray_int32_T *c2_idx);
static void c2_d_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_x,
  c2_emxArray_int32_T *c2_idx);
static void c2_emxInitStruct_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cameraParameters *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_vision_internal_c
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_vision_internal_calibration_ImageTransformer *c2_pStruct, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_rigidtform3d
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_rigidtform3d *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern **c2_pEmxArray, int32_T
   c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T1(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray);
static void c2_emxFreeStruct_vision_internal_c
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
   c2_vision_internal_calibration_ImageTransformer *c2_pStruct);
static void c2_emxFree_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_char_T **c2_pEmxArray);
static void c2_emxFreeStruct_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_cameraParameters *
   c2_pStruct);
static void c2_emxFree_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
   c2_emxArray_images_geotrans_intern **c2_pEmxArray);
static void c2_emxFreeStruct_rigidtform3d
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_rigidtform3d
   *c2_pStruct);
static void c2_emxEnsureCapacity_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real_T1
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxFreeStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_cell_wrap_22
   *c2_pStruct);
static void c2_emxTrim_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_cell_wrap_22 *c2_emxArray, int32_T c2_fromIndex,
  int32_T c2_toIndex);
static void c2_emxInitStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cell_wrap_22 *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxExpand_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_emxArray,
  int32_T c2_fromIndex, int32_T c2_toIndex, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_cell_wrap_22 *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_images_geotra
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern *c2_emxArray, int32_T c2_oldNumel,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_b_emxEnsureCapacity_images_geotra
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern *c2_emxArray, int32_T c2_oldNumel,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_b_emxInit_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern **c2_pEmxArray, int32_T
   c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_cell_wrap_22 **c2_pEmxArray);
static void c2_emxFree_int32_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray);
static void c2_emxFree_boolean_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_boolean_T
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_boolean_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cell_wrap_22 *c2_dst, const c2_cell_wrap_22 *c2_src, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T **c2_dst,
  c2_emxArray_char_T * const *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void init_dsm_address_info(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c2_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "video_and_image_blockset", 2);
  emlrtLicenseCheckR2022a(&c2_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_CameraCalImageCapture = 0U;
}

static void initialize_params_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    6U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 829);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 372, 389, 425,
                    465, false);
}

static void mdl_cleanup_runtime_resources_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  static real32_T c2_fv[3] = { 0.0F, 0.0F, 1.0F };

  static char_T c2_b_cv3[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c2_cv8[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c2_b_cv2[40] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    'm', 'e', 'r', 'a', 'I', 'n', 't', 'r', 'i', 'n', 's', 'i', 'c', 's', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v',
    'e' };

  static char_T c2_cv7[40] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 'm',
    'e', 'r', 'a', 'I', 'n', 't', 'r', 'i', 'n', 's', 'i', 'c', 's', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c2_b_cv[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 'm',
    'e', 'r', 'a', 'I', 'n', 't', 'r', 'i', 'n', 's', 'i', 'c', 's', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c2_b_cv5[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
    'm', 'e', 'r', 'a', 'I', 'n', 't', 'r', 'i', 'n', 's', 'i', 'c', 's', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c2_cv6[14] = { 'p', 'r', 'i', 'n', 'c', 'i', 'p', 'a', 'l', 'P',
    'o', 'i', 'n', 't' };

  static char_T c2_cv9[14] = { 'p', 'r', 'i', 'n', 'c', 'i', 'p', 'a', 'l', 'P',
    'o', 'i', 'n', 't' };

  static char_T c2_b_cv1[11] = { 'f', 'o', 'c', 'a', 'l', 'L', 'e', 'n', 'g',
    't', 'h' };

  static char_T c2_b_cv4[11] = { 'f', 'o', 'c', 'a', 'l', 'L', 'e', 'n', 'g',
    't', 'h' };

  c2_cameraIntrinsics c2_b_intrins;
  c2_cameraIntrinsics c2_intrins;
  c2_cameraParameters c2_lobj_0;
  c2_cameraParameters *c2_b_iobj_0;
  c2_cameraParameters *c2_iobj_0;
  c2_emxArray_real_T *c2_id;
  c2_emxArray_real_T *c2_loc;
  c2_rigidtform3d c2_b_pose;
  c2_rigidtform3d c2_pose;
  c2_rigidtform3d c2_self;
  c2_sFVkjq1LrvQBr0wOMK7gSwH c2_r;
  c2_vision_internal_codegen_cameraIntrinsicsArray c2_data_data[1];
  c2_vision_internal_codegen_cameraIntrinsicsArray c2_b_r;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_g_st;
  emlrtStack c2_h_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  const mxArray *c2_k_y = NULL;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_k;
  real_T c2_d_k;
  real_T c2_f_k;
  real_T c2_h_k;
  int32_T c2_c_k;
  int32_T c2_e_k;
  int32_T c2_g_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  real32_T c2_intrinsicMat[9];
  real32_T c2_FocalLength[2];
  real32_T c2_PrincipalPoint[2];
  real32_T c2_b_x;
  real32_T c2_c_x;
  real32_T c2_d_x;
  real32_T c2_e_x;
  real32_T c2_f_x;
  real32_T c2_g_x;
  real32_T c2_h_x;
  real32_T c2_x;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  boolean_T c2_b6;
  boolean_T c2_b7;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_d_p;
  boolean_T c2_e_b;
  boolean_T c2_e_p;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_f_p;
  boolean_T c2_g_b;
  boolean_T c2_p;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_g_st.prev = &c2_f_st;
  c2_g_st.tls = c2_f_st.tls;
  c2_h_st.prev = &c2_g_st;
  c2_h_st.tls = c2_g_st.tls;
  c2_emxInitStruct_cameraParameters(chartInstance, &c2_st, &c2_lobj_0,
    (emlrtRTEInfo *)NULL);
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c2_i = 0; c2_i < 9; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_params)[c2_i]);
  }

  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_image)[c2_i1]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  c2_FocalLength[0] = (*chartInstance->c2_params)[0];
  c2_FocalLength[1] = (*chartInstance->c2_params)[4];
  c2_PrincipalPoint[0] = (*chartInstance->c2_params)[6];
  c2_PrincipalPoint[1] = (*chartInstance->c2_params)[7];
  c2_b_st.site = &c2_c_emlrtRSI;
  c2_iobj_0 = &c2_lobj_0;
  c2_intrins.cameraIntrinsicsArrayData.size[0] = 1;
  c2_intrins.cameraIntrinsicsArrayData.size[1] = 1;
  c2_c_st.site = &c2_e_emlrtRSI;
  c2_b_iobj_0 = c2_iobj_0;
  c2_d_st.site = &c2_f_emlrtRSI;
  c2_e_st.site = &c2_i_emlrtRSI;
  c2_f_st.site = &c2_j_emlrtRSI;
  c2_g_st.site = &c2_l_emlrtRSI;
  c2_h_st.site = &c2_m_emlrtRSI;
  c2_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 2)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x = c2_FocalLength[(int32_T)c2_b_k - 1];
    c2_b_x = c2_x;
    c2_b_b = muSingleScalarIsInf(c2_b_x);
    c2_b1 = !c2_b_b;
    c2_c_x = c2_x;
    c2_c_b = muSingleScalarIsNaN(c2_c_x);
    c2_b2 = !c2_c_b;
    c2_d_b = (c2_b1 && c2_b2);
    if (c2_d_b) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_call(&c2_h_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(&c2_h_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_h_st, NULL, "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
  }

  c2_h_st.site = &c2_m_emlrtRSI;
  c2_b_p = true;
  c2_c_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k < 2)) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    c2_d_x = c2_FocalLength[(int32_T)c2_d_k - 1];
    c2_c_p = !(c2_d_x <= 0.0F);
    if (c2_c_p) {
      c2_c_k++;
    } else {
      c2_b_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_b_p) {
    c2_b3 = true;
  } else {
    c2_b3 = false;
  }

  if (!c2_b3) {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv4, 10, 0U, 1U, 0U, 2, 1, 11),
                  false);
    sf_mex_call(&c2_h_st, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                sf_mex_call(&c2_h_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_h_st, NULL, "message", 1U, 2U, 14, c2_e_y, 14, c2_f_y)));
  }

  c2_f_st.site = &c2_k_emlrtRSI;
  c2_g_st.site = &c2_n_emlrtRSI;
  c2_h_st.site = &c2_m_emlrtRSI;
  c2_d_p = true;
  c2_e_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_e_k < 2)) {
    c2_f_k = (real_T)c2_e_k + 1.0;
    c2_e_x = c2_PrincipalPoint[(int32_T)c2_f_k - 1];
    c2_f_x = c2_e_x;
    c2_e_b = muSingleScalarIsInf(c2_f_x);
    c2_b5 = !c2_e_b;
    c2_g_x = c2_e_x;
    c2_f_b = muSingleScalarIsNaN(c2_g_x);
    c2_b6 = !c2_f_b;
    c2_g_b = (c2_b5 && c2_b6);
    if (c2_g_b) {
      c2_e_k++;
    } else {
      c2_d_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_d_p) {
    c2_b4 = true;
  } else {
    c2_b4 = false;
  }

  if (!c2_b4) {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_cv5, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    sf_mex_call(&c2_h_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_g_y, 14,
                sf_mex_call(&c2_h_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_h_st, NULL, "message", 1U, 2U, 14, c2_h_y, 14, c2_i_y)));
  }

  c2_h_st.site = &c2_m_emlrtRSI;
  c2_e_p = true;
  c2_g_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_g_k < 2)) {
    c2_h_k = (real_T)c2_g_k + 1.0;
    c2_h_x = c2_PrincipalPoint[(int32_T)c2_h_k - 1];
    c2_f_p = !(c2_h_x <= 0.0F);
    if (c2_f_p) {
      c2_g_k++;
    } else {
      c2_e_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_e_p) {
    c2_b7 = true;
  } else {
    c2_b7 = false;
  }

  if (!c2_b7) {
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    sf_mex_call(&c2_h_st, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_j_y, 14,
                sf_mex_call(&c2_h_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_h_st, NULL, "message", 1U, 2U, 14, c2_k_y, 14, c2_l_y)));
  }

  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_r.focalLength[c2_i2] = c2_FocalLength[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_r.principalPoint[c2_i3] = c2_PrincipalPoint[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_r.imageSize[c2_i4] = 480.0 + 160.0 * (real_T)c2_i4;
  }

  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    c2_r.RadialDistortion[c2_i5] = 0.0;
  }

  for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
    c2_r.TangentialDistortion[c2_i6] = 0.0;
  }

  for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
    c2_intrins.FocalLength[c2_i7] = c2_r.focalLength[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_intrins.PrincipalPoint[c2_i8] = c2_r.principalPoint[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_intrins.ImageSize[c2_i9] = c2_r.imageSize[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    c2_intrins.RadialDistortion[c2_i10] = c2_r.RadialDistortion[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_intrins.TangentialDistortion[c2_i11] = c2_r.TangentialDistortion[c2_i11];
  }

  c2_intrins.Skew = 0.0;
  c2_d_st.site = &c2_g_emlrtRSI;
  c2_intrinsicMat[0] = c2_intrins.FocalLength[0];
  c2_intrinsicMat[3] = 0.0F;
  c2_intrinsicMat[6] = c2_intrins.PrincipalPoint[0];
  c2_intrinsicMat[1] = 0.0F;
  c2_intrinsicMat[4] = c2_intrins.FocalLength[1];
  c2_intrinsicMat[7] = c2_intrins.PrincipalPoint[1];
  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_intrinsicMat[c2_i12 + 2] = c2_fv[c2_i13];
    c2_i12 += 3;
  }

  for (c2_i14 = 0; c2_i14 < 9; c2_i14++) {
    c2_intrins.K[c2_i14] = c2_intrinsicMat[c2_i14];
  }

  c2_b_intrins = c2_intrins;
  c2_d_st.site = &c2_h_emlrtRSI;
  c2_intrins.CameraParameters = c2_cameraIntrinsicsImpl_cameraParameters
    (chartInstance, &c2_d_st, &c2_b_intrins, c2_b_iobj_0);
  c2_c_st.site = &c2_d_emlrtRSI;
  c2_d_st.site = &c2_rb_emlrtRSI;
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    c2_b_r.FocalLength[c2_i15] = c2_intrins.FocalLength[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    c2_b_r.PrincipalPoint[c2_i16] = c2_intrins.PrincipalPoint[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_r.ImageSize[c2_i17] = c2_intrins.ImageSize[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_b_r.RadialDistortion[c2_i18] = c2_intrins.RadialDistortion[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_b_r.TangentialDistortion[c2_i19] = c2_intrins.TangentialDistortion[c2_i19];
  }

  c2_b_r.Skew = 0.0;
  c2_e_st.site = &c2_sb_emlrtRSI;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_i22 = 0;
    for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
      c2_b_r.IntrinsicMatrix[c2_i23 + c2_i20] = c2_intrins.K[c2_i22 + c2_i21];
      c2_i22 += 3;
    }

    c2_i20 += 3;
  }

  c2_data_data[0] = c2_b_r;
  c2_intrins.cameraIntrinsicsArrayData.size[0] = 1;
  c2_intrins.cameraIntrinsicsArrayData.size[1] = 1;
  c2_intrins.cameraIntrinsicsArrayData.data[0] = c2_data_data[0];
  c2_emxInitStruct_rigidtform3d(chartInstance, &c2_st, &c2_pose, &c2_e_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, &c2_st, &c2_id, 2, (emlrtRTEInfo *)NULL);
  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_loc, 3, (emlrtRTEInfo *)NULL);
  c2_b_st.site = &c2_emlrtRSI;
  for (c2_i24 = 0; c2_i24 < 307200; c2_i24++) {
    chartInstance->c2_uv[c2_i24] = (*chartInstance->c2_image)[c2_i24];
  }

  c2_readAprilTag(chartInstance, &c2_b_st, chartInstance->c2_uv, &c2_intrins,
                  c2_id, c2_loc, &c2_pose);
  c2_emxFree_real_T(chartInstance, &c2_loc);
  c2_emxFree_real_T(chartInstance, &c2_id);
  covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0, true);
  c2_emxInitStruct_rigidtform3d(chartInstance, &c2_st, &c2_self, &c2_f_emlrtRTEI);
  c2_b_st.site = &c2_b_emlrtRSI;
  c2_b_pose = c2_pose;
  c2_OneDimArrayBehaviorTransform_parenReference(chartInstance, &c2_b_st,
    &c2_b_pose, &c2_self);
  c2_emxFreeStruct_rigidtform3d(chartInstance, &c2_pose);
  c2_i25 = 0;
  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    for (c2_i29 = 0; c2_i29 < 3; c2_i29++) {
      (*chartInstance->c2_T)[c2_i29 + c2_i25] = c2_self.R[c2_i29 + c2_i26];
    }

    c2_i25 += 4;
    c2_i26 += 3;
  }

  for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
    (*chartInstance->c2_T)[c2_i28 + 12] = c2_self.Translation[c2_i28];
  }

  c2_emxFreeStruct_rigidtform3d(chartInstance, &c2_self);
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
    (*chartInstance->c2_T)[c2_i30 + 3] = c2_dv[c2_i31];
    c2_i30 += 4;
  }

  c2_do_animation_call_c2_CameraCalImageCapture(chartInstance);
  for (c2_i32 = 0; c2_i32 < 16; c2_i32++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U, (*chartInstance->c2_T)
                      [c2_i32]);
  }

  c2_emxFreeStruct_cameraParameters(chartInstance, &c2_lobj_0);
}

static void ext_mode_exec_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_T, 0, 0U, 1U, 0U,
    2, 4, 4), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y",
    &chartInstance->c2_is_active_c2_CameraCalImageCapture, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_b_dv[16];
  int32_T c2_i;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "T",
                      c2_b_dv);
  for (c2_i = 0; c2_i < 16; c2_i++) {
    (*chartInstance->c2_T)[c2_i] = c2_b_dv[c2_i];
  }

  chartInstance->c2_is_active_c2_CameraCalImageCapture = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_CameraCalImageCapture");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void initSimStructsc2_CameraCalImageCapture
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c2_CameraCalImageCapture_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static c2_cameraParameters *c2_cameraIntrinsicsImpl_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cameraIntrinsics *c2_this, c2_cameraParameters *c2_iobj_0)
{
  static int32_T c2_iv[3] = { 1, 2, 5 };

  static int32_T c2_iv1[3] = { 3, 6, 7 };

  static real32_T c2_fv[9] = { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F,
    1.0F };

  static char_T c2_b_cv[48] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'c', 'a', 'l',
    'i', 'b', 'r', 'a', 't', 'e', ':', 'k', 'I', 'n', 't', 'r', 'i', 'n', 's',
    'i', 'c', 'M', 'a', 't', 'r', 'i', 'x', 'N', 'o', 'n', 'Z', 'e', 'r', 'o',
    'E', 'l', 'e', 'm', 'e', 'n', 't', 's' };

  static char_T c2_b_cv1[47] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'c', 'a',
    'l', 'i', 'b', 'r', 'a', 't', 'e', ':', 'i', 'n', 't', 'r', 'i', 'n', 's',
    'i', 'c', 'M', 'a', 't', 'r', 'i', 'x', 'N', 'o', 'n', 'Z', 'e', 'r', 'o',
    'E', 'l', 'e', 'm', 'e', 'n', 't', 's' };

  static char_T c2_b_cv2[15] = { 'I', 'n', 't', 'r', 'i', 'n', 's', 'i', 'c',
    'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c2_b_cv3[5] = { 'u', 'i', 'n', 't', '8' };

  static char_T c2_b_cv4[4] = { 's', 'a', 'm', 'e' };

  c2_cameraParameters *c2_b_obj;
  c2_cameraParameters *c2_b_this;
  c2_cameraParameters *c2_c_obj;
  c2_cameraParameters *c2_c_this;
  c2_cameraParameters *c2_camParams;
  c2_cameraParameters *c2_d_this;
  c2_cameraParameters *c2_e_this;
  c2_cameraParameters *c2_f_this;
  c2_cameraParameters *c2_g_this;
  c2_cameraParameters *c2_h_this;
  c2_cameraParameters *c2_obj;
  c2_sdDIrPrOimUmCOVy9iGbPrC c2_b_paramStruct;
  c2_sm65RWH2ZziLrSy5uneR4eE c2_paramStruct;
  c2_vision_internal_calibration_ImageTransformer *c2_i_this;
  c2_vision_internal_calibration_ImageTransformer *c2_j_this;
  c2_vision_internal_calibration_ImageTransformer *c2_k_this;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_g_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_varargin_4[2];
  real_T c2_varargin_6[2];
  real_T c2_varargin_8[2];
  real_T c2_b_k;
  real_T c2_b_x2;
  real_T c2_d_k;
  real_T c2_f_k;
  real_T c2_x2;
  int32_T c2_c_k;
  int32_T c2_e_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  real32_T c2_intrinsicMatrix[9];
  real32_T c2_b_intrinsicMatrix[3];
  real32_T c2_c_intrinsicMatrix[3];
  real32_T c2_b_x;
  real32_T c2_b_x1;
  real32_T c2_c_x;
  real32_T c2_x;
  real32_T c2_x1;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_d_p;
  boolean_T c2_e_p;
  boolean_T c2_exitg1;
  boolean_T c2_f_p;
  boolean_T c2_g_p;
  boolean_T c2_intrinsicMatrixAssigned;
  boolean_T c2_kAssigned;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_g_st.prev = &c2_f_st;
  c2_g_st.tls = c2_f_st.tls;
  c2_st.site = &c2_o_emlrtRSI;
  c2_b_this = c2_iobj_0;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_intrinsicMatrix[c2_i] = c2_this->K[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_varargin_4[c2_i1] = c2_this->RadialDistortion[c2_i1];
  }

  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_varargin_6[c2_i2] = c2_this->TangentialDistortion[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_varargin_8[c2_i3] = c2_this->ImageSize[c2_i3];
  }

  c2_camParams = c2_b_this;
  c2_b_st.site = &c2_p_emlrtRSI;
  c2_obj = c2_camParams;
  c2_camParams = c2_obj;
  c2_c_st.site = &c2_r_emlrtRSI;
  c2_c_this = c2_camParams;
  c2_camParams = c2_c_this;
  c2_b_st.site = &c2_q_emlrtRSI;
  c2_d_this = c2_camParams;
  c2_camParams = c2_d_this;
  c2_c_st.site = &c2_s_emlrtRSI;
  c2_d_st.site = &c2_w_emlrtRSI;
  c2_validateattributes(chartInstance, &c2_d_st, c2_intrinsicMatrix);
  for (c2_i4 = 0; c2_i4 < 9; c2_i4++) {
    c2_paramStruct.K[c2_i4] = c2_intrinsicMatrix[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 9; c2_i5++) {
    c2_paramStruct.IntrinsicMatrix[c2_i5] = c2_fv[c2_i5];
  }

  c2_d_st.site = &c2_x_emlrtRSI;
  for (c2_i6 = 0; c2_i6 < 9; c2_i6++) {
    c2_intrinsicMatrix[c2_i6] = c2_paramStruct.K[c2_i6];
  }

  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 9)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x1 = c2_intrinsicMatrix[(int32_T)c2_b_k - 1];
    c2_x2 = c2_dv1[(int32_T)c2_b_k - 1];
    c2_c_p = ((real_T)c2_x1 == c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (c2_b_p) {
    c2_p = true;
  }

  c2_kAssigned = !c2_p;
  for (c2_i7 = 0; c2_i7 < 9; c2_i7++) {
    c2_intrinsicMatrix[c2_i7] = c2_paramStruct.IntrinsicMatrix[c2_i7];
  }

  c2_d_p = false;
  c2_e_p = true;
  c2_c_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k < 9)) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    c2_b_x1 = c2_intrinsicMatrix[(int32_T)c2_d_k - 1];
    c2_b_x2 = c2_dv1[(int32_T)c2_d_k - 1];
    c2_f_p = ((real_T)c2_b_x1 == c2_b_x2);
    if (!c2_f_p) {
      c2_e_p = false;
      c2_exitg1 = true;
    } else {
      c2_c_k++;
    }
  }

  if (c2_e_p) {
    c2_d_p = true;
  }

  c2_intrinsicMatrixAssigned = !c2_d_p;
  if (c2_kAssigned) {
    c2_e_st.site = &c2_y_emlrtRSI;
    for (c2_i8 = 0; c2_i8 < 9; c2_i8++) {
      c2_intrinsicMatrix[c2_i8] = c2_paramStruct.K[c2_i8];
    }

    c2_f_st.site = &c2_bb_emlrtRSI;
    c2_validateattributes(chartInstance, &c2_f_st, c2_intrinsicMatrix);
    for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
      c2_b_intrinsicMatrix[c2_i12] = c2_intrinsicMatrix[c2_iv[c2_i12]];
    }

    if (c2_any(chartInstance, c2_b_intrinsicMatrix)) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 48),
                    false);
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
        48), false);
      sf_mex_call(&c2_e_st, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_e_st, NULL, "message", 1U, 1U, 14, c2_b_y)));
    }

    c2_i15 = 0;
    for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
      c2_i18 = 0;
      for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
        c2_paramStruct.IntrinsicMatrix[c2_i20 + c2_i15] =
          c2_paramStruct.K[c2_i18 + c2_i16];
        c2_i18 += 3;
      }

      c2_i15 += 3;
    }
  } else if (c2_intrinsicMatrixAssigned) {
    c2_e_st.site = &c2_ab_emlrtRSI;
    for (c2_i9 = 0; c2_i9 < 9; c2_i9++) {
      c2_intrinsicMatrix[c2_i9] = c2_paramStruct.IntrinsicMatrix[c2_i9];
    }

    c2_f_st.site = &c2_cb_emlrtRSI;
    c2_g_st.site = &c2_m_emlrtRSI;
    c2_g_p = true;
    c2_e_k = 0;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_e_k < 9)) {
      c2_f_k = (real_T)c2_e_k + 1.0;
      c2_x = c2_intrinsicMatrix[(int32_T)c2_f_k - 1];
      c2_b_x = c2_x;
      c2_b_b = muSingleScalarIsInf(c2_b_x);
      c2_b1 = !c2_b_b;
      c2_c_x = c2_x;
      c2_c_b = muSingleScalarIsNaN(c2_c_x);
      c2_b2 = !c2_c_b;
      c2_d_b = (c2_b1 && c2_b2);
      if (c2_d_b) {
        c2_e_k++;
      } else {
        c2_g_p = false;
        c2_exitg1 = true;
      }
    }

    if (c2_g_p) {
      c2_b = true;
    } else {
      c2_b = false;
    }

    if (!c2_b) {
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 38),
                    false);
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                    false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        15), false);
      sf_mex_call(&c2_g_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                  sf_mex_call(&c2_g_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_g_st, NULL, "message", 1U, 2U, 14, c2_d_y, 14, c2_f_y)));
    }

    for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
      c2_c_intrinsicMatrix[c2_i21] = c2_intrinsicMatrix[c2_iv1[c2_i21]];
    }

    if (c2_any(chartInstance, c2_c_intrinsicMatrix)) {
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        47), false);
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1,
        47), false);
      sf_mex_call(&c2_e_st, &c2_d_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                  sf_mex_call(&c2_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_e_st, NULL, "message", 1U, 1U, 14, c2_g_y)));
    }

    c2_i22 = 0;
    for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
      c2_i24 = 0;
      for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
        c2_paramStruct.K[c2_i25 + c2_i22] =
          c2_paramStruct.IntrinsicMatrix[c2_i24 + c2_i23];
        c2_i24 += 3;
      }

      c2_i22 += 3;
    }
  }

  for (c2_i10 = 0; c2_i10 < 9; c2_i10++) {
    c2_b_paramStruct.K[c2_i10] = c2_paramStruct.K[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 9; c2_i11++) {
    c2_b_paramStruct.IntrinsicMatrix[c2_i11] =
      c2_paramStruct.IntrinsicMatrix[c2_i11];
  }

  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    c2_b_paramStruct.RadialDistortion[c2_i13] = c2_varargin_4[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    c2_b_paramStruct.TangentialDistortion[c2_i14] = c2_varargin_6[c2_i14];
  }

  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_paramStruct.ImageSize[c2_i17] = c2_varargin_8[c2_i17];
  }

  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_b_paramStruct.WorldUnits[c2_i19] = 'm';
  }

  c2_c_st.site = &c2_t_emlrtRSI;
  c2_b_obj = c2_camParams;
  c2_camParams = c2_b_obj;
  c2_d_st.site = &c2_db_emlrtRSI;
  c2_c_obj = c2_camParams;
  c2_camParams = c2_c_obj;
  c2_e_st.site = &c2_eb_emlrtRSI;
  c2_e_this = c2_camParams;
  c2_camParams = c2_e_this;
  c2_c_st.site = &c2_u_emlrtRSI;
  c2_f_this = c2_camParams;
  for (c2_i26 = 0; c2_i26 < 9; c2_i26++) {
    c2_f_this->K[c2_i26] = c2_b_paramStruct.K[c2_i26];
  }

  c2_d_st.site = &c2_fb_emlrtRSI;
  c2_g_this = c2_f_this;
  for (c2_i27 = 0; c2_i27 < 9; c2_i27++) {
    c2_intrinsicMatrix[c2_i27] = c2_b_paramStruct.IntrinsicMatrix[c2_i27];
  }

  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 3; c2_i29++) {
    c2_i30 = 0;
    for (c2_i31 = 0; c2_i31 < 3; c2_i31++) {
      c2_g_this->K[c2_i31 + c2_i28] = c2_intrinsicMatrix[c2_i30 + c2_i29];
      c2_i30 += 3;
    }

    c2_i28 += 3;
  }

  c2_d_st.site = &c2_gb_emlrtRSI;
  c2_e_st.site = &c2_lb_emlrtRSI;
  c2_f_st.site = &c2_m_emlrtRSI;
  for (c2_i32 = 0; c2_i32 < 2; c2_i32++) {
    c2_f_this->RadialDistortion[c2_i32] =
      c2_b_paramStruct.RadialDistortion[c2_i32];
  }

  c2_d_st.site = &c2_hb_emlrtRSI;
  c2_e_st.site = &c2_mb_emlrtRSI;
  c2_f_st.site = &c2_m_emlrtRSI;
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    c2_f_this->TangentialDistortion[c2_i33] =
      c2_b_paramStruct.TangentialDistortion[c2_i33];
  }

  c2_d_st.site = &c2_ib_emlrtRSI;
  c2_CameraParametersImpl_checkImageSize(chartInstance, &c2_d_st,
    c2_b_paramStruct.ImageSize);
  c2_d_st.site = &c2_jb_emlrtRSI;
  c2_h_this = c2_f_this;
  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    c2_varargin_4[c2_i34] = c2_b_paramStruct.ImageSize[c2_i34];
  }

  c2_e_st.site = &c2_ob_emlrtRSI;
  c2_CameraParametersImpl_checkImageSize(chartInstance, &c2_e_st, c2_varargin_4);
  for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
    c2_h_this->ImageSize[c2_i35] = c2_varargin_4[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_f_this->WorldUnits[c2_i36] = c2_b_paramStruct.WorldUnits[c2_i36];
  }

  c2_f_this->EstimateSkew = false;
  c2_d_st.site = &c2_kb_emlrtRSI;
  c2_e_st.site = &c2_pb_emlrtRSI;
  c2_f_st.site = &c2_m_emlrtRSI;
  c2_f_this->NumRadialDistortionCoefficients = 2.0;
  c2_f_this->EstimateTangentialDistortion = false;
  c2_c_st.site = &c2_v_emlrtRSI;
  c2_i_this = &c2_camParams->UndistortMap;
  c2_j_this = c2_i_this;
  c2_d_st.site = &c2_qb_emlrtRSI;
  c2_k_this = c2_j_this;
  c2_j_this = c2_k_this;
  c2_i37 = c2_j_this->SizeOfImage->size[0] * c2_j_this->SizeOfImage->size[1];
  c2_j_this->SizeOfImage->size[0] = 1;
  c2_j_this->SizeOfImage->size[1] = 2;
  c2_emxEnsureCapacity_real_T(chartInstance, &c2_c_st, c2_j_this->SizeOfImage,
    c2_i37, &c2_g_emlrtRTEI);
  for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
    c2_j_this->SizeOfImage->data[c2_i38] = 0.0;
  }

  c2_i39 = c2_j_this->SizeOfImage->size[0] * c2_j_this->SizeOfImage->size[1];
  c2_j_this->SizeOfImage->size[0] = 1;
  c2_j_this->SizeOfImage->size[1] = 3;
  c2_emxEnsureCapacity_real_T(chartInstance, &c2_c_st, c2_j_this->SizeOfImage,
    c2_i39, &c2_h_emlrtRTEI);
  for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
    c2_j_this->SizeOfImage->data[c2_i40] = 0.0;
  }

  c2_i41 = c2_j_this->ClassOfImage->size[0] * c2_j_this->ClassOfImage->size[1];
  c2_j_this->ClassOfImage->size[0] = 1;
  c2_j_this->ClassOfImage->size[1] = 1;
  c2_emxEnsureCapacity_char_T(chartInstance, &c2_c_st, c2_j_this->ClassOfImage,
    c2_i41, &c2_i_emlrtRTEI);
  c2_j_this->ClassOfImage->data[0] = 'a';
  c2_i42 = c2_j_this->ClassOfImage->size[0] * c2_j_this->ClassOfImage->size[1];
  c2_j_this->ClassOfImage->size[0] = 1;
  c2_j_this->ClassOfImage->size[1] = 5;
  c2_emxEnsureCapacity_char_T(chartInstance, &c2_c_st, c2_j_this->ClassOfImage,
    c2_i42, &c2_j_emlrtRTEI);
  for (c2_i43 = 0; c2_i43 < 5; c2_i43++) {
    c2_j_this->ClassOfImage->data[c2_i43] = c2_b_cv3[c2_i43];
  }

  c2_i44 = c2_j_this->OutputView->size[0] * c2_j_this->OutputView->size[1];
  c2_j_this->OutputView->size[0] = 1;
  c2_j_this->OutputView->size[1] = 1;
  c2_emxEnsureCapacity_char_T(chartInstance, &c2_c_st, c2_j_this->OutputView,
    c2_i44, &c2_k_emlrtRTEI);
  c2_j_this->OutputView->data[0] = 'a';
  c2_i45 = c2_j_this->OutputView->size[0] * c2_j_this->OutputView->size[1];
  c2_j_this->OutputView->size[0] = 1;
  c2_j_this->OutputView->size[1] = 4;
  c2_emxEnsureCapacity_char_T(chartInstance, &c2_c_st, c2_j_this->OutputView,
    c2_i45, &c2_l_emlrtRTEI);
  for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
    c2_j_this->OutputView->data[c2_i46] = c2_b_cv4[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
    c2_j_this->Xmap[c2_i47] = 0.0;
  }

  for (c2_i48 = 0; c2_i48 < 4; c2_i48++) {
    c2_j_this->Ymap[c2_i48] = 0.0;
  }

  for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
    c2_j_this->XmapSingle[c2_i49] = 0.0F;
  }

  for (c2_i50 = 0; c2_i50 < 4; c2_i50++) {
    c2_j_this->YmapSingle[c2_i50] = 0.0F;
  }

  return c2_camParams;
}

static void c2_validateattributes(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real32_T c2_a[9])
{
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_k;
  int32_T c2_k;
  real32_T c2_b_x;
  real32_T c2_c_x;
  real32_T c2_x;
  char_T c2_u;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_m_emlrtRSI;
  c2_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 9)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x = c2_a[(int32_T)c2_b_k - 1];
    c2_b_x = c2_x;
    c2_b_b = muSingleScalarIsInf(c2_b_x);
    c2_b1 = !c2_b_b;
    c2_c_x = c2_x;
    c2_c_b = muSingleScalarIsNaN(c2_c_x);
    c2_b2 = !c2_c_b;
    c2_d_b = (c2_b1 && c2_b2);
    if (c2_d_b) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_u = 'K';
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_u, 10, 0U, 0U, 0U, 0), false);
    sf_mex_call(&c2_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14, sf_mex_call
                (&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c2_st, NULL,
      "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
  }
}

static boolean_T c2_any(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  real32_T c2_x[3])
{
  real_T c2_b_k;
  int32_T c2_i;
  int32_T c2_k;
  real32_T c2_x_data[3];
  real32_T c2_b_x;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_exitg1;
  boolean_T c2_y;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_x_data[c2_i] = c2_x[c2_i];
  }

  c2_y = false;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 3)) {
    c2_b_k = (real_T)c2_k + 1.0;
    if (c2_x_data[(int32_T)c2_b_k - 1] == 0.0F) {
      c2_b = true;
    } else {
      c2_b_x = c2_x_data[(int32_T)c2_b_k - 1];
      c2_b_b = muSingleScalarIsNaN(c2_b_x);
      if (c2_b_b) {
        c2_b = true;
      } else {
        c2_b = false;
      }
    }

    if (!c2_b) {
      c2_y = true;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  return c2_y;
}

static void c2_CameraParametersImpl_checkImageSize
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, real_T c2_imageSize[2])
{
  static char_T c2_b_cv1[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c2_b_cv[43] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'C', 'a', 'm',
    'e', 'r', 'a', 'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', 'I', 'm',
    'p', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't', 'e',
    'g', 'e', 'r' };

  static char_T c2_b_cv2[9] = { 'i', 'm', 'a', 'g', 'e', 'S', 'i', 'z', 'e' };

  emlrtStack c2_b_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_x;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_st.site = &c2_nb_emlrtRSI;
  c2_b_st.site = &c2_m_emlrtRSI;
  c2_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 2)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x = c2_imageSize[(int32_T)c2_b_k - 1];
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_c_x == c2_x) {
      c2_b_p = true;
    } else {
      c2_b_p = false;
    }

    c2_c_p = c2_b_p;
    if (c2_c_p) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c2_b_st, &c2_e_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
  }

  c2_b_st.site = &c2_m_emlrtRSI;
}

static void c2_readAprilTag(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, uint8_T c2_c_I[307200],
  c2_cameraIntrinsics *c2_varargin_2, c2_emxArray_real_T *c2_varargout_1,
  c2_emxArray_real_T *c2_varargout_2, c2_rigidtform3d *c2_varargout_3)
{
  static char_T c2_cv9[40] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'a', 'p', 'r',
    'i', 'l', 't', 'a', 'g', ':', 'u', 'n', 'r', 'e', 'c', 'o', 'g', 'n', 'i',
    'z', 'e', 'd', 'S', 't', 'r', 'i', 'n', 'g', 'C', 'h', 'o', 'i', 'c', 'e' };

  static char_T c2_cv7[16] = { 't', 'a', 'g', 'S', 't', 'a', 'n', 'd', 'a', 'r',
    'd', '4', '1', 'h', '1', '2' };

  static char_T c2_cv8[16] = { 't', 'a', 'g', 'S', 't', 'a', 'n', 'd', 'a', 'r',
    'd', '5', '2', 'h', '1', '3' };

  static char_T c2_b_cv5[14] = { 't', 'a', 'g', 'C', 'i', 'r', 'c', 'l', 'e',
    '4', '9', 'h', '1', '2' };

  static char_T c2_cv6[14] = { 't', 'a', 'g', 'C', 'u', 's', 't', 'o', 'm', '4',
    '8', 'h', '1', '2' };

  static char_T c2_b_cv4[13] = { 't', 'a', 'g', 'C', 'i', 'r', 'c', 'l', 'e',
    '2', '1', 'h', '7' };

  static char_T c2_b_cv3[8] = { 't', 'a', 'g', '3', '6', 'h', '1', '1' };

  static char_T c2_b_cv1[7] = { 't', 'a', 'g', '1', '6', 'h', '5' };

  static char_T c2_b_cv2[7] = { 't', 'a', 'g', '2', '5', 'h', '9' };

  static char_T c2_b_cv[2] = { ',', ' ' };

  static boolean_T c2_x[8] = { false, false, true, false, false, false, false,
    false };

  c2_b_cell_19 c2_b_c;
  c2_cameraIntrinsics c2_b_varargin_2;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_k;
  real_T c2_count;
  int32_T c2_escapedStr_size[2];
  int32_T c2_formatMsg_size[2];
  int32_T c2_iv[2];
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_c_b;
  int32_T c2_c_j;
  int32_T c2_c_k;
  int32_T c2_d_b;
  int32_T c2_d_j;
  int32_T c2_e_b;
  int32_T c2_e_j;
  int32_T c2_f_b;
  int32_T c2_f_j;
  int32_T c2_g_b;
  int32_T c2_g_j;
  int32_T c2_h_b;
  int32_T c2_h_j;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_b;
  int32_T c2_i_j;
  int32_T c2_j;
  int32_T c2_j_b;
  int32_T c2_j_j;
  int32_T c2_k;
  int32_T c2_k_b;
  int32_T c2_k_j;
  int32_T c2_l_b;
  int32_T c2_l_j;
  int32_T c2_loop_ub;
  int32_T c2_m_b;
  int32_T c2_m_j;
  int32_T c2_n;
  int32_T c2_nDelimChars;
  int32_T c2_n_b;
  int32_T c2_n_j;
  int32_T c2_num;
  int32_T c2_o_b;
  int32_T c2_o_j;
  int32_T c2_outidx;
  int32_T c2_outk;
  int32_T c2_p_j;
  char_T c2_formatMsg_data[109];
  char_T c2_escapedStr[2];
  char_T c2_escapedStr_data[2];
  char_T c2_c;
  boolean_T c2_x_data[8];
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_e_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_f_overflow;
  boolean_T c2_g_overflow;
  boolean_T c2_isValidFamily;
  boolean_T c2_overflow;
  boolean_T c2_y;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_st.site = &c2_vb_emlrtRSI;
  c2_b_st.site = &c2_xb_emlrtRSI;
  for (c2_i = 0; c2_i < 8; c2_i++) {
    c2_x_data[c2_i] = c2_x[c2_i];
  }

  c2_y = false;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 8)) {
    c2_b_k = (real_T)c2_k + 1.0;
    if (!c2_x_data[(int32_T)c2_b_k - 1]) {
      c2_b = true;
    } else {
      c2_b = false;
    }

    if (!c2_b) {
      c2_y = true;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  c2_count = (real_T)c2_y;
  c2_isValidFamily = (c2_count == 1.0);
  c2_c_st.site = &c2_yb_emlrtRSI;
  c2_outk = 0;
  for (c2_c_k = 0; c2_c_k < 2; c2_c_k++) {
    c2_c = c2_b_cv[c2_c_k];
    c2_escapedStr[c2_outk] = c2_c;
    c2_outk++;
  }

  c2_i1 = c2_outk;
  c2_b1 = (c2_i1 < 1);
  if (c2_b1) {
    c2_i2 = -1;
  } else {
    c2_i2 = c2_i1 - 1;
  }

  c2_escapedStr_size[1] = c2_i2 + 1;
  c2_loop_ub = c2_i2;
  for (c2_i3 = 0; c2_i3 <= c2_loop_ub; c2_i3++) {
    c2_escapedStr_data[c2_i3] = c2_escapedStr[c2_i3];
  }

  c2_d_st.site = &c2_ac_emlrtRSI;
  for (c2_i4 = 0; c2_i4 < 7; c2_i4++) {
    c2_b_c.f1[c2_i4] = c2_b_cv1[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 7; c2_i5++) {
    c2_b_c.f2[c2_i5] = c2_b_cv2[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 8; c2_i6++) {
    c2_b_c.f3[c2_i6] = c2_b_cv3[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 13; c2_i7++) {
    c2_b_c.f4[c2_i7] = c2_b_cv4[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 14; c2_i8++) {
    c2_b_c.f5[c2_i8] = c2_b_cv5[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 14; c2_i9++) {
    c2_b_c.f6[c2_i9] = c2_cv6[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 16; c2_i10++) {
    c2_b_c.f7[c2_i10] = c2_cv7[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    c2_b_c.f8[c2_i11] = c2_cv8[c2_i11];
  }

  c2_nDelimChars = 7 * c2_escapedStr_size[1] + 7;
  c2_num = c2_nDelimChars + 7;
  c2_num += 8;
  c2_num += 13;
  c2_num += 14;
  c2_num += 14;
  c2_num += 16;
  c2_num += 16;
  c2_n = c2_num;
  c2_iv[1] = c2_n;
  c2_formatMsg_size[0] = 1;
  c2_formatMsg_size[1] = c2_iv[1];
  for (c2_i12 = 0; c2_i12 < 2; c2_i12++) {
    c2_iv[c2_i12] = c2_formatMsg_size[c2_i12];
  }

  c2_formatMsg_size[0] = c2_iv[0];
  c2_formatMsg_size[1] = c2_iv[1];
  c2_outidx = 0;
  for (c2_j = 0; c2_j < 7; c2_j++) {
    c2_b_j = c2_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f1[c2_b_j];
    c2_outidx++;
  }

  c2_i13 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_b_b = c2_i13;
  c2_c_b = c2_b_b;
  if (c2_c_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i14 = (uint8_T)c2_i13 - 1;
  for (c2_c_j = 0; c2_c_j <= c2_i14; c2_c_j++) {
    c2_b_j = c2_c_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_d_j = 0; c2_d_j < 7; c2_d_j++) {
    c2_b_j = c2_d_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f2[c2_b_j];
    c2_outidx++;
  }

  c2_i15 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_d_b = c2_i15;
  c2_e_b = c2_d_b;
  if (c2_e_b < 1) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_e_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i16 = (uint8_T)c2_i15 - 1;
  for (c2_e_j = 0; c2_e_j <= c2_i16; c2_e_j++) {
    c2_b_j = c2_e_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_f_j = 0; c2_f_j < 8; c2_f_j++) {
    c2_b_j = c2_f_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f3[c2_b_j];
    c2_outidx++;
  }

  c2_i17 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_f_b = c2_i17;
  c2_g_b = c2_f_b;
  if (c2_g_b < 1) {
    c2_c_overflow = false;
  } else {
    c2_c_overflow = (c2_g_b > 2147483646);
  }

  if (c2_c_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i18 = (uint8_T)c2_i17 - 1;
  for (c2_g_j = 0; c2_g_j <= c2_i18; c2_g_j++) {
    c2_b_j = c2_g_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_h_j = 0; c2_h_j < 13; c2_h_j++) {
    c2_b_j = c2_h_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f4[c2_b_j];
    c2_outidx++;
  }

  c2_i19 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_h_b = c2_i19;
  c2_i_b = c2_h_b;
  if (c2_i_b < 1) {
    c2_d_overflow = false;
  } else {
    c2_d_overflow = (c2_i_b > 2147483646);
  }

  if (c2_d_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i20 = (uint8_T)c2_i19 - 1;
  for (c2_i_j = 0; c2_i_j <= c2_i20; c2_i_j++) {
    c2_b_j = c2_i_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_j_j = 0; c2_j_j < 14; c2_j_j++) {
    c2_b_j = c2_j_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f5[c2_b_j];
    c2_outidx++;
  }

  c2_i21 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_j_b = c2_i21;
  c2_k_b = c2_j_b;
  if (c2_k_b < 1) {
    c2_e_overflow = false;
  } else {
    c2_e_overflow = (c2_k_b > 2147483646);
  }

  if (c2_e_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i22 = (uint8_T)c2_i21 - 1;
  for (c2_k_j = 0; c2_k_j <= c2_i22; c2_k_j++) {
    c2_b_j = c2_k_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_l_j = 0; c2_l_j < 14; c2_l_j++) {
    c2_b_j = c2_l_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f6[c2_b_j];
    c2_outidx++;
  }

  c2_i23 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_l_b = c2_i23;
  c2_m_b = c2_l_b;
  if (c2_m_b < 1) {
    c2_f_overflow = false;
  } else {
    c2_f_overflow = (c2_m_b > 2147483646);
  }

  if (c2_f_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i24 = (uint8_T)c2_i23 - 1;
  for (c2_m_j = 0; c2_m_j <= c2_i24; c2_m_j++) {
    c2_b_j = c2_m_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_n_j = 0; c2_n_j < 16; c2_n_j++) {
    c2_b_j = c2_n_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f7[c2_b_j];
    c2_outidx++;
  }

  c2_i25 = c2_escapedStr_size[1];
  c2_e_st.site = &c2_bc_emlrtRSI;
  c2_n_b = c2_i25;
  c2_o_b = c2_n_b;
  if (c2_o_b < 1) {
    c2_g_overflow = false;
  } else {
    c2_g_overflow = (c2_o_b > 2147483646);
  }

  if (c2_g_overflow) {
    c2_f_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_f_st);
  }

  c2_i26 = (uint8_T)c2_i25 - 1;
  for (c2_o_j = 0; c2_o_j <= c2_i26; c2_o_j++) {
    c2_b_j = c2_o_j;
    c2_formatMsg_data[c2_outidx] = c2_escapedStr_data[c2_b_j];
    c2_outidx++;
  }

  for (c2_p_j = 0; c2_p_j < 16; c2_p_j++) {
    c2_b_j = c2_p_j;
    c2_formatMsg_data[c2_outidx] = c2_b_c.f8[c2_b_j];
    c2_outidx++;
  }

  if (!c2_isValidFamily) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_formatMsg_data, 10, 0U, 1U, 0U,
      2, c2_formatMsg_size[0], c2_formatMsg_size[1]), false);
    sf_mex_call(&c2_b_st, &c2_f_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 2U, 14, c2_c_y, 14, c2_d_y)));
  }

  c2_st.site = &c2_wb_emlrtRSI;
  for (c2_i27 = 0; c2_i27 < 307200; c2_i27++) {
    chartInstance->c2_I[c2_i27] = c2_c_I[c2_i27];
  }

  c2_b_varargin_2 = *c2_varargin_2;
  c2_readAprilTagIDPose(chartInstance, &c2_st, chartInstance->c2_I,
                        &c2_b_varargin_2, c2_varargout_1, c2_varargout_2,
                        c2_varargout_3);
}

static void c2_check_forloop_overflow_error
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp)
{
  static char_T c2_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c2_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c2_sp, &c2_g_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14, sf_mex_call
              (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
    "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
}

static void c2_readAprilTagIDPose(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, uint8_T c2_c_I[307200],
  c2_cameraIntrinsics *c2_intrinsics, c2_emxArray_real_T *c2_id,
  c2_emxArray_real_T *c2_loc, c2_rigidtform3d *c2_pose)
{
  static char_T c2_b_cv1[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'x',
    'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c2_b_cv[8] = { 't', 'a', 'g', '3', '6', 'h', '1', '1' };

  static char_T c2_b_cv2[5] = { 'i', 'n', 'p', 'u', 't' };

  void* c2_detectionsObj;
  void* c2_posesObj;
  c2_b_cell_wrap_15 c2_c[1];
  c2_b_cell_wrap_15 c2_r;
  c2_emxArray_boolean_T *c2_g_b;
  c2_emxArray_cell_wrap_22 *c2_detectedFamily;
  c2_emxArray_char_T *c2_familyNames;
  c2_emxArray_char_T *c2_tagi;
  c2_emxArray_images_geotrans_intern *c2_dataArray;
  c2_emxArray_images_geotrans_intern *c2_r1;
  c2_emxArray_images_geotrans_intern *c2_r2;
  c2_emxArray_int32_T *c2_b_familyDetectionsLen;
  c2_emxArray_int32_T *c2_c_familyDetectionsLen;
  c2_emxArray_int32_T *c2_d_idx;
  c2_emxArray_real_T *c2_familyDetectionsLen;
  c2_emxArray_real_T *c2_rotMatrices;
  c2_emxArray_real_T *c2_transVectors;
  c2_images_geotrans_internal_rigidtform3dImpl c2_data_data[1];
  c2_images_geotrans_internal_rigidtform3dImpl c2_tmp_data[1];
  c2_images_geotrans_internal_rigidtform3dImpl c2_obj;
  c2_rigidtform3d c2_this;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_n_y = NULL;
  const mxArray *c2_o_y = NULL;
  const mxArray *c2_u_y = NULL;
  const mxArray *c2_v_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_M[9];
  real_T c2_Rc[9];
  real_T c2_b_M[9];
  real_T c2_c_M[9];
  real_T c2_varargin_2[3];
  real_T c2_R;
  real_T c2_a;
  real_T c2_ab_x;
  real_T c2_b_R;
  real_T c2_b_a;
  real_T c2_b_idx;
  real_T c2_b_k;
  real_T c2_b_varargin_1;
  real_T c2_b_varargin_2;
  real_T c2_b_x;
  real_T c2_bb_x;
  real_T c2_c_a;
  real_T c2_c_n;
  real_T c2_c_varargin_1;
  real_T c2_c_varargin_2;
  real_T c2_c_x;
  real_T c2_cb_x;
  real_T c2_countValid;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_d6;
  real_T c2_d7;
  real_T c2_d8;
  real_T c2_d9;
  real_T c2_d_a;
  real_T c2_d_k;
  real_T c2_d_varargin_1;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_db_x;
  real_T c2_e_n;
  real_T c2_e_varargin_1;
  real_T c2_e_x;
  real_T c2_eb_x;
  real_T c2_f_x;
  real_T c2_farthestElement;
  real_T c2_fb_x;
  real_T c2_g_idx;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_i_x;
  real_T c2_i_y;
  real_T c2_j_b;
  real_T c2_j_x;
  real_T c2_j_y;
  real_T c2_k_b;
  real_T c2_k_x;
  real_T c2_k_y;
  real_T c2_l_x;
  real_T c2_l_y;
  real_T c2_m_x;
  real_T c2_m_y;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_p_y;
  real_T c2_q_x;
  real_T c2_q_y;
  real_T c2_r_x;
  real_T c2_r_y;
  real_T c2_s_x;
  real_T c2_s_y;
  real_T c2_start;
  real_T c2_t_x;
  real_T c2_t_y;
  real_T c2_tmpLen;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_varargin_1;
  real_T c2_w_x;
  real_T c2_x;
  real_T c2_x_x;
  real_T c2_y_x;
  int32_T c2_b_tagLength_data[2];
  int32_T c2_data_size[2];
  int32_T c2_iv[2];
  int32_T c2_tagLength_data[2];
  int32_T c2_iv1[1];
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_i;
  int32_T c2_b_j;
  int32_T c2_b_loop_ub;
  int32_T c2_b_n;
  int32_T c2_c_i;
  int32_T c2_c_idx;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_d_n;
  int32_T c2_detectedPosesSize;
  int32_T c2_detectionSize;
  int32_T c2_e_idx;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_f_idx;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_g_x;
  int32_T c2_h_b;
  int32_T c2_h_loop_ub;
  int32_T c2_h_x;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i6;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i7;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i8;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i9;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i_b;
  int32_T c2_i_loop_ub;
  int32_T c2_idx;
  int32_T c2_j;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k0;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_loop_ub;
  int32_T c2_nb;
  int32_T c2_nxin;
  int32_T c2_nxout;
  int32_T c2_o_loop_ub;
  int32_T c2_outidx;
  int32_T c2_p_loop_ub;
  int32_T c2_tagFamilyCombinedLen;
  real32_T c2_focalLength[2];
  real32_T c2_principalPoint[2];
  uint32_T c2_u;
  char_T c2_tagFamilyProc[8];
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b_is_rotation_matrix;
  boolean_T c2_b_overflow;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_is_rotation_matrix;
  boolean_T c2_overflow;
  boolean_T c2_p;
  boolean_T c2_validFlag;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_focalLength[c2_i] = c2_intrinsics->FocalLength[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_principalPoint[c2_i1] = c2_intrinsics->PrincipalPoint[c2_i1];
  }

  c2_st.site = &c2_dc_emlrtRSI;
  c2_i2 = 0;
  for (c2_i3 = 0; c2_i3 < 480; c2_i3++) {
    c2_i5 = 0;
    for (c2_i6 = 0; c2_i6 < 640; c2_i6++) {
      chartInstance->c2_b_I[c2_i6 + c2_i2] = c2_c_I[c2_i5 + c2_i3];
      c2_i5 += 480;
    }

    c2_i2 += 640;
  }

  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_tagLength_data[c2_i4] = 8 + -8 * c2_i4;
  }

  for (c2_i7 = 0; c2_i7 < 8; c2_i7++) {
    c2_r.f1[c2_i7] = c2_b_cv[c2_i7];
  }

  c2_c[0] = c2_r;
  c2_outidx = 0;
  for (c2_j = 0; c2_j < 8; c2_j++) {
    c2_b_j = c2_j;
    c2_tagFamilyProc[c2_outidx] = c2_c[0].f1[c2_b_j];
    c2_outidx++;
  }

  c2_detectionsObj = NULL;
  c2_detectionSize = 0;
  c2_tagFamilyCombinedLen = 0;
  c2_posesObj = NULL;
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_b_tagLength_data[c2_i8] = c2_tagLength_data[c2_i8];
  }

  c2_detectedPosesSize = getAprilTagIdPoseDetections(&chartInstance->c2_b_I[0],
    &c2_tagFamilyProc[0], true, 2.0F, 640, 480, &c2_detectionsObj,
    &c2_tagFamilyCombinedLen, 1, &c2_b_tagLength_data[0], &c2_focalLength[0],
    &c2_principalPoint[0], 58.5, &c2_posesObj, &c2_detectionSize);
  c2_i9 = c2_id->size[0] * c2_id->size[1];
  c2_id->size[0] = 1;
  c2_d = (real_T)c2_detectionSize;
  if (!(c2_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d, &c2_c_emlrtDCI, &c2_st);
  }

  c2_id->size[1] = (int32_T)muDoubleScalarFloor(c2_d);
  c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_id, c2_i9,
    &c2_s_emlrtRTEI);
  c2_d1 = (real_T)c2_detectionSize;
  if (!(c2_d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d1, &c2_e_emlrtDCI, &c2_st);
  }

  c2_loop_ub = (int32_T)muDoubleScalarFloor(c2_d1) - 1;
  for (c2_i10 = 0; c2_i10 <= c2_loop_ub; c2_i10++) {
    c2_id->data[c2_i10] = 1.0;
  }

  c2_i11 = c2_loc->size[0] * c2_loc->size[1] * c2_loc->size[2];
  c2_loc->size[0] = 4;
  c2_loc->size[1] = 2;
  c2_loc->size[2] = c2_detectionSize;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_loc, c2_i11,
    &c2_t_emlrtRTEI);
  c2_b_loop_ub = (c2_detectionSize << 3) - 1;
  for (c2_i12 = 0; c2_i12 <= c2_b_loop_ub; c2_i12++) {
    c2_loc->data[c2_i12] = 0.0;
  }

  c2_emxInit_real_T(chartInstance, &c2_st, &c2_familyDetectionsLen, 2,
                    &c2_sb_emlrtRTEI);
  c2_i13 = c2_familyDetectionsLen->size[0] * c2_familyDetectionsLen->size[1];
  c2_familyDetectionsLen->size[0] = 1;
  c2_familyDetectionsLen->size[1] = c2_detectionSize;
  c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_familyDetectionsLen,
    c2_i13, &c2_u_emlrtRTEI);
  c2_c_loop_ub = c2_detectionSize - 1;
  for (c2_i14 = 0; c2_i14 <= c2_c_loop_ub; c2_i14++) {
    c2_familyDetectionsLen->data[c2_i14] = 0.0;
  }

  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_rotMatrices, 3, &c2_v_emlrtRTEI);
  c2_i15 = c2_rotMatrices->size[0] * c2_rotMatrices->size[1] *
    c2_rotMatrices->size[2];
  c2_rotMatrices->size[0] = 3;
  c2_rotMatrices->size[1] = 3;
  c2_d2 = (real_T)c2_detectedPosesSize;
  if (!(c2_d2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d2, &c2_d_emlrtDCI, &c2_st);
  }

  c2_rotMatrices->size[2] = (int32_T)muDoubleScalarFloor(c2_d2);
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_rotMatrices, c2_i15,
    &c2_v_emlrtRTEI);
  c2_d3 = (real_T)c2_detectedPosesSize;
  if (!(c2_d3 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d3, &c2_f_emlrtDCI, &c2_st);
  }

  c2_d_loop_ub = 9 * (int32_T)muDoubleScalarFloor(c2_d3) - 1;
  for (c2_i16 = 0; c2_i16 <= c2_d_loop_ub; c2_i16++) {
    c2_rotMatrices->data[c2_i16] = 0.0;
  }

  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_transVectors, 3, &c2_w_emlrtRTEI);
  c2_i17 = c2_transVectors->size[0] * c2_transVectors->size[1] *
    c2_transVectors->size[2];
  c2_transVectors->size[0] = 3;
  c2_transVectors->size[1] = 1;
  c2_transVectors->size[2] = c2_detectedPosesSize;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_transVectors, c2_i17,
    &c2_w_emlrtRTEI);
  c2_e_loop_ub = 3 * c2_detectedPosesSize - 1;
  for (c2_i18 = 0; c2_i18 <= c2_e_loop_ub; c2_i18++) {
    c2_transVectors->data[c2_i18] = 0.0;
  }

  c2_b_st.site = &c2_jc_emlrtRSI;
  c2_n = c2_tagFamilyCombinedLen;
  c2_d4 = 1.0;
  if (!(c2_d4 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d4, &c2_g_emlrtDCI, &c2_b_st);
  }

  c2_d5 = (real_T)c2_n;
  if (!(c2_d5 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c2_d5, &c2_g_emlrtDCI, &c2_b_st);
  }

  c2_iv[1] = (int32_T)muDoubleScalarFloor(c2_d5);
  c2_emxInit_char_T(chartInstance, &c2_b_st, &c2_familyNames, 2,
                    &c2_tb_emlrtRTEI);
  c2_i19 = c2_familyNames->size[0] * c2_familyNames->size[1];
  c2_familyNames->size[0] = 1;
  c2_familyNames->size[1] = c2_iv[1];
  c2_emxEnsureCapacity_char_T(chartInstance, &c2_b_st, c2_familyNames, c2_i19,
    &c2_x_emlrtRTEI);
  c2_f_loop_ub = c2_iv[1] - 1;
  for (c2_i20 = 0; c2_i20 <= c2_f_loop_ub; c2_i20++) {
    c2_familyNames->data[c2_i20] = ' ';
  }

  initialiseOutput(&c2_id->data[0], &c2_loc->data[0],
                   &c2_familyDetectionsLen->data[0], &c2_familyNames->data[0],
                   c2_detectionsObj, c2_detectionSize);
  initialisePoses(&c2_rotMatrices->data[0], &c2_transVectors->data[0],
                  c2_detectionsObj, c2_posesObj, c2_detectedPosesSize);
  c2_iv[0] = 1;
  c2_iv[1] = c2_detectionSize;
  c2_emxInit_cell_wrap_22(chartInstance, &c2_st, &c2_detectedFamily, 2,
    &c2_rb_emlrtRTEI);
  c2_i21 = c2_detectedFamily->size[0] * c2_detectedFamily->size[1];
  c2_detectedFamily->size[0] = c2_iv[0];
  c2_detectedFamily->size[1] = c2_iv[1];
  c2_b_st.site = &c2_dc_emlrtRSI;
  c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_b_st, c2_detectedFamily,
    c2_i21, &c2_y_emlrtRTEI);
  for (c2_i22 = 0; c2_i22 < c2_iv[1]; c2_i22++) {
    c2_i23 = c2_detectedFamily->size[1] - 1;
    if ((c2_i22 < 0) || (c2_i22 > c2_i23)) {
      emlrtDynamicBoundsCheckR2012b(c2_i22, 0, c2_i23, &c2_g_emlrtBCI, &c2_st);
    }

    c2_i24 = c2_i22;
    c2_detectedFamily->data[c2_i24].f1->size[0] = 1;
    c2_i25 = c2_detectedFamily->size[1] - 1;
    if ((c2_i22 < 0) || (c2_i22 > c2_i25)) {
      emlrtDynamicBoundsCheckR2012b(c2_i22, 0, c2_i25, &c2_g_emlrtBCI, &c2_st);
    }

    c2_i26 = c2_i22;
    c2_detectedFamily->data[c2_i26].f1->size[1] = 0;
  }

  c2_tmpLen = 0.0;
  c2_b_st.site = &c2_kc_emlrtRSI;
  c2_b = c2_detectionSize;
  c2_b_b = c2_b;
  if (c2_b_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  c2_u = (uint32_T)c2_detectionSize;
  if (c2_u > 2147483647U) {
    c2_u = 2147483647U;
  }

  c2_i27 = (int32_T)c2_u - 1;
  c2_i28 = c2_detectedFamily->size[0] * c2_detectedFamily->size[1];
  c2_detectedFamily->size[0] = c2_iv[0];
  c2_detectedFamily->size[1] = c2_iv[1];
  c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_st, c2_detectedFamily,
    c2_i28, &c2_ab_emlrtRTEI);
  c2_emxInit_char_T(chartInstance, &c2_st, &c2_tagi, 2, &c2_bb_emlrtRTEI);
  for (c2_b_i = 0; c2_b_i <= c2_i27; c2_b_i++) {
    c2_c_i = c2_b_i;
    c2_start = c2_tmpLen + 1.0;
    c2_i29 = c2_familyDetectionsLen->size[1];
    c2_i30 = c2_c_i + 1;
    if ((c2_i30 < 1) || (c2_i30 > c2_i29)) {
      emlrtDynamicBoundsCheckR2012b(c2_i30, 1, c2_i29, &c2_h_emlrtBCI, &c2_st);
    }

    c2_d6 = (c2_start + c2_familyDetectionsLen->data[c2_i30 - 1]) - 1.0;
    c2_c_b = (c2_start > c2_d6);
    if (c2_c_b) {
      c2_i34 = 0;
      c2_i36 = -1;
    } else {
      if (c2_start != (real_T)(int32_T)muDoubleScalarFloor(c2_start)) {
        emlrtIntegerCheckR2012b(c2_start, &c2_emlrtDCI, &c2_st);
      }

      c2_i37 = c2_familyNames->size[1];
      c2_i38 = (int32_T)c2_start;
      if ((c2_i38 < 1) || (c2_i38 > c2_i37)) {
        emlrtDynamicBoundsCheckR2012b(c2_i38, 1, c2_i37, &c2_d_emlrtBCI, &c2_st);
      }

      c2_i34 = c2_i38 - 1;
      if (c2_d6 != (real_T)(int32_T)muDoubleScalarFloor(c2_d6)) {
        emlrtIntegerCheckR2012b(c2_d6, &c2_b_emlrtDCI, &c2_st);
      }

      c2_i42 = c2_familyNames->size[1];
      c2_i43 = (int32_T)c2_d6;
      if ((c2_i43 < 1) || (c2_i43 > c2_i42)) {
        emlrtDynamicBoundsCheckR2012b(c2_i43, 1, c2_i42, &c2_e_emlrtBCI, &c2_st);
      }

      c2_i36 = c2_i43 - 1;
    }

    c2_i39 = c2_tagi->size[0] * c2_tagi->size[1];
    c2_tagi->size[0] = 1;
    c2_tagi->size[1] = (c2_i36 - c2_i34) + 1;
    c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_tagi, c2_i39,
      &c2_bb_emlrtRTEI);
    c2_g_loop_ub = c2_i36 - c2_i34;
    for (c2_i41 = 0; c2_i41 <= c2_g_loop_ub; c2_i41++) {
      c2_tagi->data[c2_i41] = c2_familyNames->data[c2_i34 + c2_i41];
    }

    c2_i44 = c2_detectedFamily->size[1] - 1;
    if ((c2_c_i < 0) || (c2_c_i > c2_i44)) {
      emlrtDynamicBoundsCheckR2012b(c2_c_i, 0, c2_i44, &c2_f_emlrtBCI, &c2_st);
    }

    c2_i46 = c2_c_i;
    c2_i47 = c2_detectedFamily->data[c2_i46].f1->size[0] *
      c2_detectedFamily->data[c2_i46].f1->size[1];
    c2_detectedFamily->data[c2_i46].f1->size[0] = 1;
    c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_detectedFamily->
      data[c2_i46].f1, c2_i47, &c2_cb_emlrtRTEI);
    c2_i49 = c2_detectedFamily->size[1] - 1;
    if ((c2_c_i < 0) || (c2_c_i > c2_i49)) {
      emlrtDynamicBoundsCheckR2012b(c2_c_i, 0, c2_i49, &c2_f_emlrtBCI, &c2_st);
    }

    c2_i50 = c2_c_i;
    c2_i51 = c2_detectedFamily->data[c2_i50].f1->size[0] *
      c2_detectedFamily->data[c2_i50].f1->size[1];
    c2_detectedFamily->data[c2_i50].f1->size[1] = c2_tagi->size[1];
    c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_detectedFamily->
      data[c2_i50].f1, c2_i51, &c2_cb_emlrtRTEI);
    c2_i53 = c2_detectedFamily->size[1] - 1;
    if ((c2_c_i < 0) || (c2_c_i > c2_i53)) {
      emlrtDynamicBoundsCheckR2012b(c2_c_i, 0, c2_i53, &c2_f_emlrtBCI, &c2_st);
    }

    c2_i55 = c2_detectedFamily->size[1] - 1;
    if ((c2_c_i < 0) || (c2_c_i > c2_i55)) {
      emlrtDynamicBoundsCheckR2012b(c2_c_i, 0, c2_i55, &c2_f_emlrtBCI, &c2_st);
    }

    c2_i_loop_ub = c2_tagi->size[0] * c2_tagi->size[1] - 1;
    for (c2_i59 = 0; c2_i59 <= c2_i_loop_ub; c2_i59++) {
      c2_i61 = c2_detectedFamily->size[1] - 1;
      if ((c2_c_i < 0) || (c2_c_i > c2_i61)) {
        emlrtDynamicBoundsCheckR2012b(c2_c_i, 0, c2_i61, &c2_n_emlrtBCI, &c2_st);
      }

      c2_detectedFamily->data[c2_c_i].f1->data[c2_i59] = c2_tagi->data[c2_i59];
    }

    c2_i60 = c2_familyDetectionsLen->size[1];
    c2_i62 = c2_c_i + 1;
    if ((c2_i62 < 1) || (c2_i62 > c2_i60)) {
      emlrtDynamicBoundsCheckR2012b(c2_i62, 1, c2_i60, &c2_i_emlrtBCI, &c2_st);
    }

    c2_tmpLen += c2_familyDetectionsLen->data[c2_i62 - 1];
  }

  c2_emxFree_char_T(chartInstance, &c2_tagi);
  c2_emxFree_char_T(chartInstance, &c2_familyNames);
  c2_familyDetectionsLen->size[0] = 1;
  c2_familyDetectionsLen->size[1] = 0;
  for (c2_i31 = 0; c2_i31 < 9; c2_i31++) {
    c2_pose->R[c2_i31] = c2_dv1[c2_i31];
  }

  for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
    c2_pose->Translation[c2_i32] = 0.0;
  }

  for (c2_i33 = 0; c2_i33 < 9; c2_i33++) {
    c2_obj.R[c2_i33] = c2_dv1[c2_i33];
  }

  for (c2_i35 = 0; c2_i35 < 3; c2_i35++) {
    c2_obj.Translation[c2_i35] = 0.0;
  }

  c2_data_size[0] = 1;
  c2_data_size[1] = 1;
  c2_data_data[0] = c2_obj;
  c2_i40 = c2_pose->Data->size[0] * c2_pose->Data->size[1];
  c2_pose->Data->size[0] = 1;
  c2_pose->Data->size[1] = 1;
  c2_emxEnsureCapacity_images_geotra(chartInstance, c2_sp, c2_pose->Data, c2_i40,
    &c2_eb_emlrtRTEI);
  c2_h_loop_ub = c2_data_size[0] * c2_data_size[1] - 1;
  for (c2_i45 = 0; c2_i45 <= c2_h_loop_ub; c2_i45++) {
    c2_pose->Data->data[c2_i45] = c2_data_data[c2_i45];
  }

  c2_countValid = 1.0;
  c2_d7 = (real_T)c2_rotMatrices->size[2];
  c2_i48 = (int32_T)c2_d7 - 1;
  c2_emxInitStruct_rigidtform3d(chartInstance, c2_sp, &c2_this, &c2_ub_emlrtRTEI);
  c2_emxInit_images_geotrans_interna(chartInstance, c2_sp, &c2_dataArray, 2,
    &c2_vb_emlrtRTEI);
  c2_emxInit_images_geotrans_interna(chartInstance, c2_sp, &c2_r1, 2,
    &c2_wb_emlrtRTEI);
  c2_b_emxInit_images_geotrans_interna(chartInstance, c2_sp, &c2_r2, 1,
    &c2_wb_emlrtRTEI);
  for (c2_idx = 0; c2_idx <= c2_i48; c2_idx++) {
    c2_b_idx = (real_T)c2_idx + 1.0;
    c2_st.site = &c2_ec_emlrtRSI;
    c2_i52 = c2_rotMatrices->size[2];
    c2_i54 = (int32_T)c2_b_idx;
    if ((c2_i54 < 1) || (c2_i54 > c2_i52)) {
      emlrtDynamicBoundsCheckR2012b(c2_i54, 1, c2_i52, &c2_emlrtBCI, &c2_st);
    }

    c2_c_idx = c2_i54 - 1;
    for (c2_i56 = 0; c2_i56 < 3; c2_i56++) {
      for (c2_i58 = 0; c2_i58 < 3; c2_i58++) {
        c2_M[c2_i58 + 3 * c2_i56] = c2_rotMatrices->data[(c2_i58 + 3 * c2_i56) +
          9 * c2_c_idx];
      }
    }

    c2_b_st.site = &c2_te_emlrtRSI;
    c2_c_st.site = &c2_m_emlrtRSI;
    c2_p = true;
    c2_k = 0;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_k < 9)) {
      c2_b_k = (real_T)c2_k + 1.0;
      c2_x = c2_M[(int32_T)c2_b_k - 1];
      c2_b_x = c2_x;
      c2_d_b = muDoubleScalarIsInf(c2_b_x);
      c2_b2 = !c2_d_b;
      c2_c_x = c2_x;
      c2_e_b = muDoubleScalarIsNaN(c2_c_x);
      c2_b3 = !c2_e_b;
      c2_f_b = (c2_b2 && c2_b3);
      if (c2_f_b) {
        c2_k++;
      } else {
        c2_p = false;
        c2_exitg1 = true;
      }
    }

    if (c2_p) {
      c2_b1 = true;
    } else {
      c2_b1 = false;
    }

    if (!c2_b1) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                    false);
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        5), false);
      sf_mex_call(&c2_c_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
    }

    c2_b_st.site = &c2_ue_emlrtRSI;
    c2_d_x = c2_det(chartInstance, &c2_b_st, c2_M) - 1.0;
    c2_e_x = c2_d_x;
    c2_f_x = c2_e_x;
    c2_d_y = muDoubleScalarAbs(c2_f_x);
    if (c2_d_y > 0.001) {
      c2_validFlag = false;
    } else {
      c2_validFlag = true;
    }

    if (c2_validFlag) {
      c2_st.site = &c2_fc_emlrtRSI;
      c2_i67 = c2_rotMatrices->size[2];
      c2_i68 = (int32_T)c2_b_idx;
      if ((c2_i68 < 1) || (c2_i68 > c2_i67)) {
        emlrtDynamicBoundsCheckR2012b(c2_i68, 1, c2_i67, &c2_b_emlrtBCI, &c2_st);
      }

      c2_e_idx = c2_i68 - 1;
      for (c2_i69 = 0; c2_i69 < 3; c2_i69++) {
        for (c2_i71 = 0; c2_i71 < 3; c2_i71++) {
          c2_M[c2_i71 + 3 * c2_i69] = c2_rotMatrices->data[(c2_i69 + 3 * c2_i71)
            + 9 * c2_e_idx];
        }
      }

      c2_i70 = c2_transVectors->size[2];
      c2_i72 = (int32_T)c2_b_idx;
      if ((c2_i72 < 1) || (c2_i72 > c2_i70)) {
        emlrtDynamicBoundsCheckR2012b(c2_i72, 1, c2_i70, &c2_c_emlrtBCI, &c2_st);
      }

      c2_f_idx = c2_i72 - 1;
      for (c2_i73 = 0; c2_i73 < 3; c2_i73++) {
        c2_varargin_2[c2_i73] = c2_transVectors->data[c2_i73 + 3 * c2_f_idx];
      }

      c2_b_st.site = &c2_ve_emlrtRSI;
      c2_c_st.site = &c2_xe_emlrtRSI;
      c2_d_st.site = &c2_ye_emlrtRSI;
      c2_e_st.site = &c2_af_emlrtRSI;
      c2_constrainToRotationMatrix3D(chartInstance, &c2_e_st, c2_M, c2_Rc);
      c2_e_st.site = &c2_bf_emlrtRSI;
      c2_f_st.site = &c2_cf_emlrtRSI;
      c2_varargin_1 = c2_norm(chartInstance, &c2_f_st, c2_M);
      c2_f_st.site = &c2_cf_emlrtRSI;
      c2_b_varargin_2 = c2_norm(chartInstance, &c2_f_st, c2_Rc);
      c2_i_x = c2_varargin_1;
      c2_i_y = c2_b_varargin_2;
      c2_j_x = c2_i_x;
      c2_j_y = c2_i_y;
      c2_k_x = c2_j_x;
      c2_k_y = c2_j_y;
      c2_a = c2_k_x;
      c2_j_b = c2_k_y;
      c2_l_x = c2_a;
      c2_l_y = c2_j_b;
      c2_m_x = c2_l_x;
      c2_m_y = c2_l_y;
      c2_R = muDoubleScalarMax(c2_m_x, c2_m_y);
      c2_b_varargin_1 = c2_R;
      c2_n_x = c2_b_varargin_1;
      c2_o_x = c2_n_x;
      c2_p_x = c2_o_x;
      c2_b_a = c2_p_x;
      c2_q_x = c2_b_a;
      c2_r_x = c2_q_x;
      c2_R = muDoubleScalarMax(c2_r_x, 1.223247290044539E-294);
      for (c2_i80 = 0; c2_i80 < 9; c2_i80++) {
        c2_b_M[c2_i80] = c2_M[c2_i80] - c2_Rc[c2_i80];
      }

      c2_f_st.site = &c2_df_emlrtRSI;
      c2_is_rotation_matrix = (c2_norm(chartInstance, &c2_f_st, c2_b_M) / c2_R <=
        1.8189894035458565E-12);
      if (!c2_is_rotation_matrix) {
        c2_n_y = NULL;
        sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        c2_o_y = NULL;
        sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        sf_mex_call(&c2_c_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_n_y, 14,
                    sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_o_y)));
      }

      c2_b_st.site = &c2_we_emlrtRSI;
      c2_c_st.site = &c2_xe_emlrtRSI;
      c2_d_st.site = &c2_ye_emlrtRSI;
      c2_e_st.site = &c2_af_emlrtRSI;
      c2_constrainToRotationMatrix3D(chartInstance, &c2_e_st, c2_M, c2_Rc);
      c2_e_st.site = &c2_bf_emlrtRSI;
      c2_f_st.site = &c2_cf_emlrtRSI;
      c2_c_varargin_1 = c2_norm(chartInstance, &c2_f_st, c2_M);
      c2_f_st.site = &c2_cf_emlrtRSI;
      c2_c_varargin_2 = c2_norm(chartInstance, &c2_f_st, c2_Rc);
      c2_s_x = c2_c_varargin_1;
      c2_p_y = c2_c_varargin_2;
      c2_t_x = c2_s_x;
      c2_q_y = c2_p_y;
      c2_u_x = c2_t_x;
      c2_r_y = c2_q_y;
      c2_c_a = c2_u_x;
      c2_k_b = c2_r_y;
      c2_v_x = c2_c_a;
      c2_s_y = c2_k_b;
      c2_w_x = c2_v_x;
      c2_t_y = c2_s_y;
      c2_b_R = muDoubleScalarMax(c2_w_x, c2_t_y);
      c2_d_varargin_1 = c2_b_R;
      c2_x_x = c2_d_varargin_1;
      c2_y_x = c2_x_x;
      c2_ab_x = c2_y_x;
      c2_d_a = c2_ab_x;
      c2_bb_x = c2_d_a;
      c2_cb_x = c2_bb_x;
      c2_b_R = muDoubleScalarMax(c2_cb_x, 1.223247290044539E-294);
      for (c2_i85 = 0; c2_i85 < 9; c2_i85++) {
        c2_c_M[c2_i85] = c2_M[c2_i85] - c2_Rc[c2_i85];
      }

      c2_f_st.site = &c2_df_emlrtRSI;
      c2_b_is_rotation_matrix = (c2_norm(chartInstance, &c2_f_st, c2_c_M) /
        c2_b_R <= 1.8189894035458565E-12);
      if (!c2_b_is_rotation_matrix) {
        c2_u_y = NULL;
        sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        c2_v_y = NULL;
        sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        sf_mex_call(&c2_c_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_u_y, 14,
                    sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_v_y)));
      }

      for (c2_i86 = 0; c2_i86 < 9; c2_i86++) {
        c2_obj.R[c2_i86] = c2_Rc[c2_i86];
      }

      for (c2_i87 = 0; c2_i87 < 3; c2_i87++) {
        c2_obj.Translation[c2_i87] = c2_varargin_2[c2_i87];
      }

      c2_data_size[0] = 1;
      c2_data_size[1] = 1;
      c2_data_data[0] = c2_obj;
      c2_i88 = c2_this.Data->size[0] * c2_this.Data->size[1];
      c2_this.Data->size[0] = 1;
      c2_this.Data->size[1] = 1;
      c2_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_this.Data,
        c2_i88, &c2_eb_emlrtRTEI);
      c2_n_loop_ub = c2_data_size[0] * c2_data_size[1] - 1;
      for (c2_i89 = 0; c2_i89 <= c2_n_loop_ub; c2_i89++) {
        c2_this.Data->data[c2_i89] = c2_data_data[c2_i89];
      }

      c2_st.site = &c2_fc_emlrtRSI;
      c2_g_idx = c2_countValid;
      c2_e_varargin_1 = c2_g_idx;
      c2_db_x = c2_e_varargin_1;
      c2_eb_x = c2_db_x;
      c2_fb_x = c2_eb_x;
      c2_gb_x = c2_fb_x;
      c2_hb_x = c2_gb_x;
      c2_farthestElement = c2_hb_x;
      c2_c_n = (real_T)c2_pose->Data->size[1];
      if (c2_farthestElement > c2_c_n) {
        c2_i90 = c2_r1->size[0] * c2_r1->size[1];
        c2_r1->size[0] = 1;
        if (c2_farthestElement != (real_T)(int32_T)muDoubleScalarFloor
            (c2_farthestElement)) {
          emlrtIntegerCheckR2012b(c2_farthestElement, &c2_h_emlrtDCI, &c2_st);
        }

        c2_r1->size[1] = (int32_T)c2_farthestElement;
        c2_b_st.site = &c2_fc_emlrtRSI;
        c2_emxEnsureCapacity_images_geotra(chartInstance, &c2_b_st, c2_r1,
          c2_i90, &c2_lb_emlrtRTEI);
        c2_i93 = c2_dataArray->size[0] * c2_dataArray->size[1];
        c2_dataArray->size[0] = c2_r1->size[0];
        c2_dataArray->size[1] = c2_r1->size[1];
        c2_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_dataArray,
          c2_i93, &c2_nb_emlrtRTEI);
        c2_d9 = (real_T)c2_pose->Data->size[1];
        c2_i94 = (int32_T)c2_d9 - 1;
        for (c2_d_n = 0; c2_d_n <= c2_i94; c2_d_n++) {
          c2_e_n = (real_T)c2_d_n + 1.0;
          c2_iv1[0] = c2_dataArray->size[1];
          c2_i96 = c2_r2->size[0];
          c2_r2->size[0] = c2_pose->Data->size[1];
          c2_b_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_r2,
            c2_i96, &c2_pb_emlrtRTEI);
          c2_o_loop_ub = c2_pose->Data->size[1] - 1;
          for (c2_i98 = 0; c2_i98 <= c2_o_loop_ub; c2_i98++) {
            c2_r2->data[c2_i98] = c2_pose->Data->data[c2_i98];
          }

          c2_i99 = c2_r2->size[0] - 1;
          c2_i101 = (int32_T)c2_e_n - 1;
          if ((c2_i101 < 0) || (c2_i101 > c2_i99)) {
            emlrtDynamicBoundsCheckR2012b(c2_i101, 0, c2_i99, &c2_l_emlrtBCI,
              &c2_st);
          }

          c2_i102 = c2_iv1[0] - 1;
          c2_i103 = (int32_T)c2_e_n - 1;
          if ((c2_i103 < 0) || (c2_i103 > c2_i102)) {
            emlrtDynamicBoundsCheckR2012b(c2_i103, 0, c2_i102, &c2_m_emlrtBCI,
              &c2_st);
          }

          c2_dataArray->data[c2_i103] = c2_r2->data[c2_i101];
        }

        c2_iv1[0] = c2_dataArray->size[1];
        c2_tmp_data[0] = c2_this.Data->data[0];
        c2_i95 = c2_iv1[0] - 1;
        if (c2_g_idx != (real_T)(int32_T)muDoubleScalarFloor(c2_g_idx)) {
          emlrtIntegerCheckR2012b(c2_g_idx, &c2_j_emlrtDCI, &c2_st);
        }

        c2_i97 = (int32_T)c2_g_idx - 1;
        if ((c2_i97 < 0) || (c2_i97 > c2_i95)) {
          emlrtDynamicBoundsCheckR2012b(c2_i97, 0, c2_i95, &c2_k_emlrtBCI,
            &c2_st);
        }

        c2_dataArray->data[c2_i97] = c2_tmp_data[0];
        c2_i100 = c2_pose->Data->size[0] * c2_pose->Data->size[1];
        c2_pose->Data->size[0] = 1;
        c2_pose->Data->size[1] = c2_dataArray->size[1];
        c2_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_pose->Data,
          c2_i100, &c2_qb_emlrtRTEI);
        c2_p_loop_ub = c2_dataArray->size[0] * c2_dataArray->size[1] - 1;
        for (c2_i104 = 0; c2_i104 <= c2_p_loop_ub; c2_i104++) {
          c2_pose->Data->data[c2_i104] = c2_dataArray->data[c2_i104];
        }
      } else {
        c2_iv1[0] = c2_pose->Data->size[1];
        c2_tmp_data[0] = c2_this.Data->data[0];
        c2_i91 = c2_iv1[0] - 1;
        if (c2_g_idx != (real_T)(int32_T)muDoubleScalarFloor(c2_g_idx)) {
          emlrtIntegerCheckR2012b(c2_g_idx, &c2_i_emlrtDCI, &c2_st);
        }

        c2_i92 = (int32_T)c2_g_idx - 1;
        if ((c2_i92 < 0) || (c2_i92 > c2_i91)) {
          emlrtDynamicBoundsCheckR2012b(c2_i92, 0, c2_i91, &c2_j_emlrtBCI,
            &c2_st);
        }

        c2_pose->Data->data[c2_i92] = c2_tmp_data[0];
      }

      c2_countValid++;
    } else {
      c2_i65 = c2_familyDetectionsLen->size[1];
      c2_i66 = c2_familyDetectionsLen->size[0] * c2_familyDetectionsLen->size[1];
      c2_familyDetectionsLen->size[0] = 1;
      c2_familyDetectionsLen->size[1]++;
      c2_st.site = &c2_ig_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_familyDetectionsLen,
        c2_i66, &c2_gb_emlrtRTEI);
      c2_familyDetectionsLen->data[c2_i65] = c2_b_idx;
    }
  }

  c2_emxFree_images_geotrans_interna(chartInstance, &c2_r2);
  c2_emxFree_images_geotrans_interna(chartInstance, &c2_r1);
  c2_emxFree_images_geotrans_interna(chartInstance, &c2_dataArray);
  c2_emxFreeStruct_rigidtform3d(chartInstance, &c2_this);
  c2_emxFree_real_T(chartInstance, &c2_transVectors);
  c2_emxFree_real_T(chartInstance, &c2_rotMatrices);
  c2_st.site = &c2_hc_emlrtRSI;
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_d_idx, 2, &c2_fb_emlrtRTEI);
  c2_i57 = c2_d_idx->size[0] * c2_d_idx->size[1];
  c2_d_idx->size[0] = 1;
  c2_d_idx->size[1] = c2_familyDetectionsLen->size[1];
  c2_b_st.site = &c2_hc_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_b_st, c2_d_idx, c2_i57,
    &c2_fb_emlrtRTEI);
  c2_j_loop_ub = c2_familyDetectionsLen->size[0] * c2_familyDetectionsLen->size
    [1] - 1;
  for (c2_i63 = 0; c2_i63 <= c2_j_loop_ub; c2_i63++) {
    c2_d_idx->data[c2_i63] = (int32_T)c2_familyDetectionsLen->data[c2_i63];
  }

  c2_b_st.site = &c2_lf_emlrtRSI;
  c2_b_n = c2_id->size[1];
  c2_b_p = true;
  c2_d8 = (real_T)c2_d_idx->size[1];
  c2_i64 = (int32_T)c2_d8 - 1;
  c2_c_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k <= c2_i64)) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    if (c2_d_idx->data[(int32_T)c2_d_k - 1] > c2_b_n) {
      c2_b_p = false;
      c2_exitg1 = true;
    } else {
      c2_g_x = c2_d_idx->data[(int32_T)c2_d_k - 1];
      c2_h_x = c2_g_x;
      if (c2_d_idx->data[(int32_T)c2_d_k - 1] != c2_h_x) {
        c2_b_p = false;
        c2_exitg1 = true;
      } else {
        c2_c_k++;
      }
    }
  }

  if (!c2_b_p) {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c2_b_st, &c2_m_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_b_st.site = &c2_mf_emlrtRSI;
  c2_nxin = c2_id->size[1];
  c2_emxInit_boolean_T(chartInstance, &c2_b_st, &c2_g_b, 2, &c2_xb_emlrtRTEI);
  c2_c_st.site = &c2_nf_emlrtRSI;
  c2_make_bitarray(chartInstance, &c2_c_st, c2_nxin, c2_d_idx, c2_g_b);
  c2_emxFree_int32_T(chartInstance, &c2_d_idx);
  c2_c_st.site = &c2_of_emlrtRSI;
  c2_nxout = c2_nxin - c2_num_true(chartInstance, &c2_c_st, c2_g_b);
  c2_nb = c2_g_b->size[1];
  c2_k0 = -1;
  c2_c_st.site = &c2_pf_emlrtRSI;
  c2_h_b = c2_nxin;
  c2_i_b = c2_h_b;
  if (c2_i_b < 1) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_i_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_d_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
  }

  for (c2_e_k = 0; c2_e_k < c2_nxin; c2_e_k++) {
    c2_f_k = c2_e_k;
    if ((c2_f_k + 1 > c2_nb) || (!c2_g_b->data[c2_f_k])) {
      c2_k0++;
      c2_id->data[c2_k0] = c2_id->data[c2_f_k];
    }
  }

  c2_emxFree_boolean_T(chartInstance, &c2_g_b);
  if (!(c2_nxout <= c2_nxin)) {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c2_b_st, &c2_n_emlrtMCI, "error", 0U, 2U, 14, c2_g_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 1U, 14, c2_h_y)));
  }

  c2_b4 = (c2_nxout < 1);
  if (c2_b4) {
    c2_i74 = 0;
  } else {
    c2_i74 = c2_nxout;
  }

  c2_i75 = c2_id->size[0] * c2_id->size[1];
  c2_id->size[1] = c2_i74;
  c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_id, c2_i75,
    &c2_hb_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_b_familyDetectionsLen, 2,
                     &c2_ib_emlrtRTEI);
  c2_i76 = c2_b_familyDetectionsLen->size[0] * c2_b_familyDetectionsLen->size[1];
  c2_b_familyDetectionsLen->size[0] = 1;
  c2_b_familyDetectionsLen->size[1] = c2_familyDetectionsLen->size[1];
  c2_st.site = &c2_gc_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_b_familyDetectionsLen,
    c2_i76, &c2_ib_emlrtRTEI);
  c2_k_loop_ub = c2_familyDetectionsLen->size[0] * c2_familyDetectionsLen->size
    [1] - 1;
  for (c2_i77 = 0; c2_i77 <= c2_k_loop_ub; c2_i77++) {
    c2_b_familyDetectionsLen->data[c2_i77] = (int32_T)
      c2_familyDetectionsLen->data[c2_i77];
  }

  c2_st.site = &c2_gc_emlrtRSI;
  c2_c_nullAssignment(chartInstance, &c2_st, c2_loc, c2_b_familyDetectionsLen);
  c2_emxFree_int32_T(chartInstance, &c2_b_familyDetectionsLen);
  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_c_familyDetectionsLen, 2,
                     &c2_jb_emlrtRTEI);
  c2_i78 = c2_c_familyDetectionsLen->size[0] * c2_c_familyDetectionsLen->size[1];
  c2_c_familyDetectionsLen->size[0] = 1;
  c2_c_familyDetectionsLen->size[1] = c2_familyDetectionsLen->size[1];
  c2_st.site = &c2_ic_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_c_familyDetectionsLen,
    c2_i78, &c2_jb_emlrtRTEI);
  c2_l_loop_ub = c2_familyDetectionsLen->size[0] * c2_familyDetectionsLen->size
    [1] - 1;
  for (c2_i79 = 0; c2_i79 <= c2_l_loop_ub; c2_i79++) {
    c2_c_familyDetectionsLen->data[c2_i79] = (int32_T)
      c2_familyDetectionsLen->data[c2_i79];
  }

  c2_emxFree_real_T(chartInstance, &c2_familyDetectionsLen);
  c2_st.site = &c2_ic_emlrtRSI;
  c2_d_nullAssignment(chartInstance, &c2_st, c2_detectedFamily,
                      c2_c_familyDetectionsLen);
  c2_emxFree_int32_T(chartInstance, &c2_c_familyDetectionsLen);
  c2_emxFree_cell_wrap_22(chartInstance, &c2_detectedFamily);
  c2_i81 = c2_loc->size[0] * c2_loc->size[1] * c2_loc->size[2];
  c2_i82 = c2_loc->size[0] * c2_loc->size[1] * c2_loc->size[2];
  c2_loc->size[0] = 4;
  c2_loc->size[1] = 2;
  c2_st.site = &c2_jg_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_loc, c2_i82,
    &c2_kb_emlrtRTEI);
  c2_i83 = c2_i81;
  c2_m_loop_ub = c2_i83 - 1;
  for (c2_i84 = 0; c2_i84 <= c2_m_loop_ub; c2_i84++) {
    c2_loc->data[c2_i84]++;
  }
}

static void c2_constrainToRotationMatrix3D
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, real_T c2_R[9], real_T c2_Rc[9])
{
  static int32_T c2_iv[2] = { 3, 3 };

  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_R_clamped[9];
  real_T c2_U[9];
  real_T c2_V[9];
  real_T c2_b_R_clamped[9];
  real_T c2_b_dv[9];
  real_T c2_minval[9];
  real_T c2_b_Rc[6];
  real_T c2_S[3];
  real_T c2_b_ex;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d_x;
  real_T c2_ex;
  real_T c2_x;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  boolean_T c2_allFiniteA;
  boolean_T c2_b_p;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  for (c2_k = 0; c2_k < 9; c2_k++) {
    c2_c_k = c2_k;
    c2_x = c2_R[c2_c_k];
    c2_b_x = c2_x;
    c2_ex = muDoubleScalarMin(c2_b_x, 1.0);
    c2_minval[c2_c_k] = c2_ex;
  }

  for (c2_b_k = 0; c2_b_k < 9; c2_b_k++) {
    c2_d_k = c2_b_k;
    c2_c_x = c2_minval[c2_d_k];
    c2_d_x = c2_c_x;
    c2_b_ex = muDoubleScalarMax(c2_d_x, -1.0);
    c2_R_clamped[c2_d_k] = c2_b_ex;
  }

  c2_st.site = &c2_lc_emlrtRSI;
  c2_b_st.site = &c2_oc_emlrtRSI;
  c2_c_st.site = &c2_rc_emlrtRSI;
  c2_d_st.site = &c2_sc_emlrtRSI;
  c2_p = c2_flatVectorAllOrAny(chartInstance, &c2_d_st, c2_R_clamped, c2_iv);
  c2_b_p = !c2_p;
  c2_allFiniteA = !c2_b_p;
  if (c2_allFiniteA) {
    c2_b_st.site = &c2_pc_emlrtRSI;
    c2_c_st.site = &c2_uc_emlrtRSI;
    c2_d_st.site = &c2_vc_emlrtRSI;
    for (c2_i1 = 0; c2_i1 < 9; c2_i1++) {
      c2_minval[c2_i1] = c2_R_clamped[c2_i1];
    }

    c2_e_st.site = &c2_wc_emlrtRSI;
    c2_xzsvdc(chartInstance, &c2_e_st, c2_minval, c2_U, c2_S, c2_V);
  } else {
    c2_b_st.site = &c2_qc_emlrtRSI;
    c2_c_st.site = &c2_uc_emlrtRSI;
    c2_d_st.site = &c2_vc_emlrtRSI;
    for (c2_i = 0; c2_i < 9; c2_i++) {
      c2_b_dv[c2_i] = 0.0;
    }

    c2_e_st.site = &c2_wc_emlrtRSI;
    c2_xzsvdc(chartInstance, &c2_e_st, c2_b_dv, c2_U, c2_S, c2_V);
    for (c2_i2 = 0; c2_i2 < 9; c2_i2++) {
      c2_U[c2_i2] = rtNaN;
    }

    for (c2_i4 = 0; c2_i4 < 9; c2_i4++) {
      c2_V[c2_i4] = rtNaN;
    }
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_i5 = 0;
    for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
      c2_Rc[c2_i5 + c2_i3] = 0.0;
      c2_i11 = 0;
      for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
        c2_Rc[c2_i5 + c2_i3] += c2_U[c2_i11 + c2_i3] * c2_V[c2_i11 + c2_i6];
        c2_i11 += 3;
      }

      c2_i5 += 3;
    }
  }

  c2_st.site = &c2_mc_emlrtRSI;
  if (c2_det(chartInstance, &c2_st, c2_Rc) < 0.0) {
    c2_i7 = 0;
    c2_i9 = 0;
    for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
      for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
        c2_b_Rc[c2_i14 + c2_i7] = c2_Rc[(c2_i9 - c2_i14) + 1];
      }

      c2_i7 += 2;
      c2_i9 += 3;
    }

    c2_i13 = 0;
    c2_i15 = 0;
    for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
      for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
        c2_Rc[c2_i18 + c2_i13] = c2_b_Rc[c2_i18 + c2_i15];
      }

      c2_i13 += 3;
      c2_i15 += 2;
    }
  }

  for (c2_i8 = 0; c2_i8 < 9; c2_i8++) {
    c2_b_R_clamped[c2_i8] = c2_R_clamped[c2_i8] - c2_Rc[c2_i8];
  }

  c2_st.site = &c2_nc_emlrtRSI;
  c2_d = c2_norm(chartInstance, &c2_st, c2_b_R_clamped) / 2.2204460492503131E-16;
  if (c2_d < 10.0) {
    for (c2_i16 = 0; c2_i16 < 9; c2_i16++) {
      c2_Rc[c2_i16] = c2_R_clamped[c2_i16];
    }
  }
}

static boolean_T c2_flatVectorAllOrAny(SFc2_CameraCalImageCaptureInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, real_T c2_x_data[], int32_T c2_x_size
  [2])
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_x;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_i;
  int32_T c2_k;
  int32_T c2_nx;
  boolean_T c2_b1;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_f_b;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_nx = c2_x_size[0] * c2_x_size[1];
  c2_p = true;
  c2_st.site = &c2_tc_emlrtRSI;
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (c2_b_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_b_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
  }

  c2_i = (uint8_T)c2_nx - 1;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_b_k = c2_k;
    if (c2_p) {
      c2_x = c2_x_data[c2_b_k];
      c2_b_x = c2_x;
      c2_c_b = muDoubleScalarIsInf(c2_b_x);
      c2_d_b = !c2_c_b;
      c2_c_x = c2_x;
      c2_e_b = muDoubleScalarIsNaN(c2_c_x);
      c2_b1 = !c2_e_b;
      c2_f_b = (c2_d_b && c2_b1);
      if (c2_f_b) {
        c2_b_p = true;
      } else {
        c2_b_p = false;
      }
    } else {
      c2_b_p = false;
    }

    c2_p = c2_b_p;
  }

  return c2_p;
}

static void c2_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_A[9], real_T c2_U[9],
                      real_T c2_S[3], real_T c2_V[9])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_A[9];
  real_T c2_b_work[3];
  real_T c2_e[3];
  real_T c2_s[3];
  real_T c2_work[3];
  real_T c2_a;
  real_T c2_a__1;
  real_T c2_a__2;
  real_T c2_a__3;
  real_T c2_ab_a;
  real_T c2_ab_b;
  real_T c2_ab_x;
  real_T c2_absx;
  real_T c2_ac_x;
  real_T c2_b_absx;
  real_T c2_b_cs;
  real_T c2_b_d;
  real_T c2_b_f;
  real_T c2_b_s;
  real_T c2_b_sn;
  real_T c2_b_t1;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_bb_a;
  real_T c2_bb_b;
  real_T c2_bb_x;
  real_T c2_c_a;
  real_T c2_c_c;
  real_T c2_c_cs;
  real_T c2_c_f;
  real_T c2_c_s;
  real_T c2_c_sn;
  real_T c2_c_t1;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_cb_a;
  real_T c2_cb_b;
  real_T c2_cb_x;
  real_T c2_cs;
  real_T c2_d;
  real_T c2_d_c;
  real_T c2_d_cs;
  real_T c2_d_f;
  real_T c2_d_s;
  real_T c2_d_sn;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_db_a;
  real_T c2_db_b;
  real_T c2_db_x;
  real_T c2_e_c;
  real_T c2_e_s;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_eb_a;
  real_T c2_eb_b;
  real_T c2_eb_x;
  real_T c2_emm1;
  real_T c2_eqds;
  real_T c2_f;
  real_T c2_f_c;
  real_T c2_f_s;
  real_T c2_f_x;
  real_T c2_f_y;
  real_T c2_fb_a;
  real_T c2_fb_b;
  real_T c2_fb_x;
  real_T c2_g;
  real_T c2_g_c;
  real_T c2_g_s;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_gb_a;
  real_T c2_gb_b;
  real_T c2_gb_x;
  real_T c2_h_c;
  real_T c2_h_s;
  real_T c2_h_x;
  real_T c2_h_y;
  real_T c2_hb_a;
  real_T c2_hb_b;
  real_T c2_hb_x;
  real_T c2_i_c;
  real_T c2_i_s;
  real_T c2_i_x;
  real_T c2_i_y;
  real_T c2_ib_x;
  real_T c2_iter;
  real_T c2_j_b;
  real_T c2_j_c;
  real_T c2_j_x;
  real_T c2_j_y;
  real_T c2_jb_x;
  real_T c2_k_a;
  real_T c2_k_c;
  real_T c2_k_x;
  real_T c2_k_y;
  real_T c2_kase;
  real_T c2_kb_x;
  real_T c2_l_b;
  real_T c2_l_x;
  real_T c2_l_y;
  real_T c2_lb_x;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_m_x;
  real_T c2_m_y;
  real_T c2_mb_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_x;
  real_T c2_nb_x;
  real_T c2_nrm;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_o_x;
  real_T c2_ob_x;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_p_x;
  real_T c2_pb_x;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_x;
  real_T c2_qb_x;
  real_T c2_r;
  real_T c2_r_a;
  real_T c2_r_b;
  real_T c2_r_x;
  real_T c2_rb_x;
  real_T c2_rt;
  real_T c2_s_a;
  real_T c2_s_b;
  real_T c2_s_x;
  real_T c2_sb_x;
  real_T c2_scale;
  real_T c2_shift;
  real_T c2_sm;
  real_T c2_smm1;
  real_T c2_sn;
  real_T c2_snorm;
  real_T c2_sqds;
  real_T c2_t;
  real_T c2_t1;
  real_T c2_t_a;
  real_T c2_t_b;
  real_T c2_t_x;
  real_T c2_tb_x;
  real_T c2_test;
  real_T c2_test0;
  real_T c2_u_a;
  real_T c2_u_b;
  real_T c2_u_x;
  real_T c2_ub_x;
  real_T c2_v_x;
  real_T c2_vb_x;
  real_T c2_w_x;
  real_T c2_wb_x;
  real_T c2_x;
  real_T c2_x_a;
  real_T c2_x_b;
  real_T c2_x_x;
  real_T c2_xb_x;
  real_T c2_y;
  real_T c2_y_a;
  real_T c2_y_b;
  real_T c2_y_x;
  real_T c2_yb_x;
  real_T c2_ztest;
  real_T c2_ztest0;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ii;
  int32_T c2_b_ix0;
  int32_T c2_b_jj;
  int32_T c2_b_k;
  int32_T c2_b_q;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_c_ii;
  int32_T c2_c_jj;
  int32_T c2_c_k;
  int32_T c2_c_q;
  int32_T c2_colk;
  int32_T c2_colkp1;
  int32_T c2_colm;
  int32_T c2_colq;
  int32_T c2_colqm1;
  int32_T c2_colqp1;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_ii;
  int32_T c2_d_jj;
  int32_T c2_d_k;
  int32_T c2_d_q;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_ii;
  int32_T c2_e_jj;
  int32_T c2_e_k;
  int32_T c2_e_q;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_ii;
  int32_T c2_f_k;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_ii;
  int32_T c2_g_k;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_h_ii;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_i_ii;
  int32_T c2_ii;
  int32_T c2_ix0;
  int32_T c2_j_a;
  int32_T c2_j_ii;
  int32_T c2_jj;
  int32_T c2_k;
  int32_T c2_k_b;
  int32_T c2_k_ii;
  int32_T c2_kp1;
  int32_T c2_l_a;
  int32_T c2_l_ii;
  int32_T c2_m;
  int32_T c2_mm1;
  int32_T c2_n;
  int32_T c2_nmq;
  int32_T c2_nmqp1;
  int32_T c2_q;
  int32_T c2_qjj;
  int32_T c2_qm1;
  int32_T c2_qp1;
  int32_T c2_qp1jj;
  int32_T c2_qq;
  int32_T c2_qs;
  int32_T c2_v_a;
  int32_T c2_v_b;
  int32_T c2_w_a;
  int32_T c2_w_b;
  boolean_T c2_apply_transform;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_e_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_exitg2;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_s[c2_i] = 0.0;
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_e[c2_i1] = 0.0;
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_work[c2_i2] = 0.0;
  }

  for (c2_i3 = 0; c2_i3 < 9; c2_i3++) {
    c2_U[c2_i3] = 0.0;
  }

  for (c2_i4 = 0; c2_i4 < 9; c2_i4++) {
    c2_V[c2_i4] = 0.0;
  }

  for (c2_q = 0; c2_q < 2; c2_q++) {
    c2_b_q = c2_q;
    c2_qp1 = c2_b_q + 2;
    c2_qm1 = c2_b_q;
    c2_qq = (c2_b_q + 3 * c2_qm1) + 1;
    c2_nmq = 2 - c2_b_q;
    c2_nmqp1 = c2_nmq + 1;
    c2_apply_transform = false;
    c2_st.site = &c2_pd_emlrtRSI;
    c2_nrm = c2_xnrm2(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq);
    if (c2_nrm > 0.0) {
      c2_apply_transform = true;
      c2_absx = c2_nrm;
      c2_d = c2_A[c2_qq - 1];
      if (c2_d < 0.0) {
        c2_y = -c2_absx;
      } else {
        c2_y = c2_absx;
      }

      c2_s[c2_b_q] = c2_y;
      c2_st.site = &c2_od_emlrtRSI;
      c2_n = c2_nmqp1;
      c2_a = c2_s[c2_b_q];
      c2_ix0 = c2_qq;
      c2_j_x = c2_a;
      c2_l_x = c2_j_x;
      c2_n_x = c2_l_x;
      c2_d_y = muDoubleScalarAbs(c2_n_x);
      if (c2_d_y >= 1.0020841800044864E-292) {
        c2_b_st.site = &c2_sd_emlrtRSI;
        c2_f_xscal(chartInstance, &c2_b_st, c2_n, 1.0 / c2_a, c2_A, c2_ix0);
      } else {
        c2_b_a = c2_n - 1;
        c2_c = c2_b_a;
        c2_c_b = c2_c;
        c2_b_c = c2_c_b;
        c2_d_a = c2_ix0;
        c2_d_b = c2_b_c;
        c2_i8 = c2_d_a + c2_d_b;
        c2_b_st.site = &c2_td_emlrtRSI;
        c2_f_a = c2_ix0;
        c2_e_b = c2_i8;
        c2_h_a = c2_f_a;
        c2_g_b = c2_e_b;
        if (c2_h_a > c2_g_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_g_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_c_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
        }

        for (c2_d_k = c2_ix0; c2_d_k <= c2_i8; c2_d_k++) {
          c2_A[c2_d_k - 1] /= c2_a;
        }
      }

      c2_A[c2_qq - 1]++;
      c2_s[c2_b_q] = -c2_s[c2_b_q];
    } else {
      c2_s[c2_b_q] = 0.0;
    }

    for (c2_b_jj = c2_qp1; c2_b_jj < 4; c2_b_jj++) {
      c2_qjj = (c2_b_q + 3 * (c2_b_jj - 1)) + 1;
      if (c2_apply_transform) {
        c2_st.site = &c2_nd_emlrtRSI;
        c2_t = c2_xdotc(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq, c2_A,
                        c2_qjj);
        c2_t = -(c2_t / c2_A[c2_b_q + 3 * c2_b_q]);
        c2_g_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq, c2_A, c2_qjj);
      }

      c2_e[c2_b_jj - 1] = c2_A[c2_qjj - 1];
    }

    for (c2_e_ii = c2_b_q + 1; c2_e_ii < 4; c2_e_ii++) {
      c2_U[(c2_e_ii + 3 * c2_b_q) - 1] = c2_A[(c2_e_ii + 3 * c2_b_q) - 1];
    }

    if (c2_b_q + 1 <= 1) {
      c2_st.site = &c2_md_emlrtRSI;
      c2_nrm = c2_b_xnrm2(chartInstance, &c2_st, c2_e, c2_qp1);
      if (c2_nrm == 0.0) {
        c2_e[0] = 0.0;
      } else {
        c2_b_absx = c2_nrm;
        c2_b_d = c2_e[c2_qp1 - 1];
        if (c2_b_d < 0.0) {
          c2_c_y = -c2_b_absx;
        } else {
          c2_c_y = c2_b_absx;
        }

        c2_e[0] = c2_c_y;
        c2_st.site = &c2_ld_emlrtRSI;
        c2_c_a = c2_e[0];
        c2_b_ix0 = c2_qp1;
        c2_q_x = c2_c_a;
        c2_s_x = c2_q_x;
        c2_u_x = c2_s_x;
        c2_g_y = muDoubleScalarAbs(c2_u_x);
        if (c2_g_y >= 1.0020841800044864E-292) {
          c2_b_st.site = &c2_sd_emlrtRSI;
          c2_g_xscal(chartInstance, &c2_b_st, 1.0 / c2_c_a, c2_e, c2_b_ix0);
        } else {
          c2_e_a = c2_b_ix0 + 1;
          c2_i10 = c2_e_a;
          c2_b_st.site = &c2_td_emlrtRSI;
          c2_j_a = c2_b_ix0;
          c2_i_b = c2_i10;
          c2_l_a = c2_j_a;
          c2_k_b = c2_i_b;
          if (c2_l_a > c2_k_b) {
            c2_d_overflow = false;
          } else {
            c2_d_overflow = (c2_k_b > 2147483646);
          }

          if (c2_d_overflow) {
            c2_c_st.site = &c2_cc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
          }

          for (c2_f_k = c2_b_ix0; c2_f_k <= c2_i10; c2_f_k++) {
            c2_e[c2_f_k - 1] /= c2_c_a;
          }
        }

        c2_e[c2_qp1 - 1]++;
        c2_e[0] = -c2_e[0];
        for (c2_l_ii = c2_qp1; c2_l_ii < 4; c2_l_ii++) {
          c2_work[c2_l_ii - 1] = 0.0;
        }

        for (c2_d_jj = c2_qp1; c2_d_jj < 4; c2_d_jj++) {
          c2_qp1jj = c2_qp1 + 3 * (c2_d_jj - 1);
          for (c2_i11 = 0; c2_i11 < 9; c2_i11++) {
            c2_b_A[c2_i11] = c2_A[c2_i11];
          }

          c2_h_xaxpy(chartInstance, c2_nmq, c2_e[c2_d_jj - 1], c2_b_A, c2_qp1jj,
                     c2_work, c2_qp1);
        }

        for (c2_e_jj = c2_qp1; c2_e_jj < 4; c2_e_jj++) {
          c2_t = -c2_e[c2_e_jj - 1] / c2_e[c2_qp1 - 1];
          c2_qp1jj = c2_qp1 + 3 * (c2_e_jj - 1);
          for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
            c2_b_work[c2_i12] = c2_work[c2_i12];
          }

          c2_i_xaxpy(chartInstance, c2_nmq, c2_t, c2_b_work, c2_qp1, c2_A,
                     c2_qp1jj);
        }
      }

      for (c2_h_ii = c2_qp1; c2_h_ii < 4; c2_h_ii++) {
        c2_V[c2_h_ii - 1] = c2_e[c2_h_ii - 1];
      }
    }
  }

  c2_m = 2;
  c2_s[2] = c2_A[8];
  c2_e[1] = c2_A[7];
  c2_e[2] = 0.0;
  for (c2_ii = 0; c2_ii < 3; c2_ii++) {
    c2_b_ii = c2_ii;
    c2_U[6 + c2_b_ii] = 0.0;
  }

  c2_U[8] = 1.0;
  for (c2_c_q = 1; c2_c_q >= 0; c2_c_q--) {
    c2_qp1 = c2_c_q;
    c2_nmq = 3 - c2_c_q;
    c2_nmqp1 = c2_nmq;
    c2_qq = c2_c_q + 3 * c2_c_q;
    if (c2_s[c2_c_q] != 0.0) {
      for (c2_c_jj = c2_qp1 + 2; c2_c_jj < 4; c2_c_jj++) {
        c2_qjj = (c2_c_q + 3 * (c2_c_jj - 1)) + 1;
        c2_st.site = &c2_kd_emlrtRSI;
        c2_t = c2_xdotc(chartInstance, &c2_st, c2_nmqp1, c2_U, c2_qq + 1, c2_U,
                        c2_qjj);
        c2_t = -(c2_t / c2_U[c2_qq]);
        c2_g_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq + 1, c2_U, c2_qjj);
      }

      for (c2_g_ii = c2_c_q + 1; c2_g_ii < 4; c2_g_ii++) {
        c2_U[(c2_g_ii + 3 * c2_c_q) - 1] = -c2_U[(c2_g_ii + 3 * c2_c_q) - 1];
      }

      c2_U[c2_qq]++;
      c2_i5 = c2_c_q;
      c2_st.site = &c2_jd_emlrtRSI;
      c2_b = c2_i5;
      c2_b_b = c2_b;
      if (c2_b_b < 1) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_b_b > 2147483646);
      }

      if (c2_overflow) {
        c2_b_st.site = &c2_cc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
      }

      c2_i7 = (uint8_T)c2_i5 - 1;
      for (c2_k_ii = 0; c2_k_ii <= c2_i7; c2_k_ii++) {
        c2_U[3 * c2_c_q] = 0.0;
      }
    } else {
      for (c2_d_ii = 0; c2_d_ii < 3; c2_d_ii++) {
        c2_b_ii = c2_d_ii;
        c2_U[c2_b_ii + 3 * c2_c_q] = 0.0;
      }

      c2_U[c2_qq] = 1.0;
    }
  }

  for (c2_d_q = 2; c2_d_q >= 0; c2_d_q--) {
    if ((c2_d_q + 1 <= 1) && (c2_e[0] != 0.0)) {
      for (c2_jj = 0; c2_jj < 2; c2_jj++) {
        c2_qp1jj = 2 + 3 * (c2_jj + 1);
        c2_st.site = &c2_id_emlrtRSI;
        c2_t = c2_xdotc(chartInstance, &c2_st, 2, c2_V, 2, c2_V, c2_qp1jj);
        c2_t = -(c2_t / c2_V[1]);
        c2_g_xaxpy(chartInstance, 2, c2_t, 2, c2_V, c2_qp1jj);
      }
    }

    for (c2_c_ii = 0; c2_c_ii < 3; c2_c_ii++) {
      c2_b_ii = c2_c_ii;
      c2_V[c2_b_ii + 3 * c2_d_q] = 0.0;
    }

    c2_V[c2_d_q + 3 * c2_d_q] = 1.0;
  }

  for (c2_e_q = 0; c2_e_q < 3; c2_e_q++) {
    c2_b_q = c2_e_q;
    if (c2_s[c2_b_q] != 0.0) {
      c2_x = c2_s[c2_b_q];
      c2_b_x = c2_x;
      c2_d_x = c2_b_x;
      c2_rt = muDoubleScalarAbs(c2_d_x);
      c2_r = c2_s[c2_b_q] / c2_rt;
      c2_s[c2_b_q] = c2_rt;
      if (c2_b_q + 1 < 3) {
        c2_e[c2_b_q] /= c2_r;
      }

      c2_colq = 3 * c2_b_q;
      c2_st.site = &c2_hd_emlrtRSI;
      c2_h_xscal(chartInstance, &c2_st, c2_r, c2_U, c2_colq + 1);
    }

    if ((c2_b_q + 1 < 3) && (c2_e[c2_b_q] != 0.0)) {
      c2_c_x = c2_e[c2_b_q];
      c2_f_x = c2_c_x;
      c2_h_x = c2_f_x;
      c2_rt = muDoubleScalarAbs(c2_h_x);
      c2_r = c2_rt / c2_e[c2_b_q];
      c2_e[c2_b_q] = c2_rt;
      c2_s[c2_b_q + 1] *= c2_r;
      c2_colqp1 = 3 * (c2_b_q + 1);
      c2_st.site = &c2_gd_emlrtRSI;
      c2_h_xscal(chartInstance, &c2_st, c2_r, c2_V, c2_colqp1 + 1);
    }
  }

  c2_iter = 0.0;
  c2_snorm = 0.0;
  for (c2_f_ii = 0; c2_f_ii < 3; c2_f_ii++) {
    c2_b_ii = c2_f_ii;
    c2_e_x = c2_s[c2_b_ii];
    c2_g_x = c2_e_x;
    c2_i_x = c2_g_x;
    c2_b_y = muDoubleScalarAbs(c2_i_x);
    c2_k_x = c2_e[c2_b_ii];
    c2_m_x = c2_k_x;
    c2_o_x = c2_m_x;
    c2_e_y = muDoubleScalarAbs(c2_o_x);
    c2_snorm = muDoubleScalarMax(c2_snorm, muDoubleScalarMax(c2_b_y, c2_e_y));
  }

  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_m + 1 > 0)) {
    if (c2_iter >= 75.0) {
      sf_mex_call(c2_sp, &c2_h_emlrtMCI, "error", 0U, 2U, 14,
                  c2_emlrt_marshallOut(chartInstance, c2_cv5), 14, sf_mex_call
                  (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
        "message", 1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv5))));
      c2_exitg1 = true;
    } else {
      c2_b_q = c2_m;
      c2_i6 = c2_m;
      c2_i_ii = c2_i6;
      c2_exitg2 = false;
      while ((!c2_exitg2) && (c2_i_ii > -1)) {
        c2_b_q = c2_i_ii;
        if (c2_i_ii == 0) {
          c2_exitg2 = true;
        } else {
          c2_p_x = c2_s[c2_i_ii - 1];
          c2_r_x = c2_p_x;
          c2_t_x = c2_r_x;
          c2_f_y = muDoubleScalarAbs(c2_t_x);
          c2_x_x = c2_s[c2_i_ii];
          c2_ab_x = c2_x_x;
          c2_bb_x = c2_ab_x;
          c2_h_y = muDoubleScalarAbs(c2_bb_x);
          c2_test0 = c2_f_y + c2_h_y;
          c2_hb_x = c2_e[c2_i_ii - 1];
          c2_kb_x = c2_hb_x;
          c2_nb_x = c2_kb_x;
          c2_ztest0 = muDoubleScalarAbs(c2_nb_x);
          if ((c2_ztest0 <= 2.2204460492503131E-16 * c2_test0) || (c2_ztest0 <=
               1.0020841800044864E-292) || ((c2_iter > 20.0) && (c2_ztest0 <=
                2.2204460492503131E-16 * c2_snorm))) {
            c2_e[c2_i_ii - 1] = 0.0;
            c2_exitg2 = true;
          } else {
            c2_i_ii--;
          }
        }
      }

      if (c2_b_q == c2_m) {
        c2_kase = 4.0;
      } else {
        c2_qs = c2_m + 1;
        c2_j_ii = c2_m + 1;
        c2_exitg2 = false;
        while ((!c2_exitg2) && (c2_j_ii >= c2_b_q)) {
          c2_qs = c2_j_ii;
          if (c2_j_ii == c2_b_q) {
            c2_exitg2 = true;
          } else {
            c2_test = 0.0;
            if (c2_j_ii < c2_m + 1) {
              c2_db_x = c2_e[c2_j_ii - 1];
              c2_fb_x = c2_db_x;
              c2_jb_x = c2_fb_x;
              c2_test = muDoubleScalarAbs(c2_jb_x);
            }

            if (c2_j_ii > c2_b_q + 1) {
              c2_ib_x = c2_e[c2_j_ii - 2];
              c2_mb_x = c2_ib_x;
              c2_pb_x = c2_mb_x;
              c2_j_y = muDoubleScalarAbs(c2_pb_x);
              c2_test += c2_j_y;
            }

            c2_lb_x = c2_s[c2_j_ii - 1];
            c2_ob_x = c2_lb_x;
            c2_rb_x = c2_ob_x;
            c2_ztest = muDoubleScalarAbs(c2_rb_x);
            if ((c2_ztest <= 2.2204460492503131E-16 * c2_test) || (c2_ztest <=
                 1.0020841800044864E-292)) {
              c2_s[c2_j_ii - 1] = 0.0;
              c2_exitg2 = true;
            } else {
              c2_j_ii--;
            }
          }
        }

        if (c2_qs == c2_b_q) {
          c2_kase = 3.0;
        } else if (c2_qs == c2_m + 1) {
          c2_kase = 1.0;
        } else {
          c2_kase = 2.0;
          c2_b_q = c2_qs;
        }
      }

      switch ((int32_T)c2_kase) {
       case 1:
        c2_f = c2_e[c2_m - 1];
        c2_e[c2_m - 1] = 0.0;
        c2_i9 = c2_m;
        for (c2_c_k = c2_i9; c2_c_k >= c2_b_q + 1; c2_c_k--) {
          c2_t1 = c2_s[c2_c_k - 1];
          c2_st.site = &c2_fd_emlrtRSI;
          c2_k_a = c2_t1;
          c2_j_b = c2_f;
          c2_b_f = c2_j_b;
          c2_b_t1 = c2_k_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_m_a = c2_b_t1;
          c2_l_b = c2_b_f;
          c2_m_b = c2_l_b;
          c2_n_a = c2_m_a;
          c2_o_a = c2_n_a;
          c2_n_b = c2_m_b;
          c2_o_b = c2_n_b;
          c2_q_a = c2_o_a;
          c2_c_c = 0.0;
          c2_b_s = 0.0;
          drotg(&c2_q_a, &c2_o_b, &c2_c_c, &c2_b_s);
          c2_n_a = c2_q_a;
          c2_m_b = c2_o_b;
          c2_d_c = c2_c_c;
          c2_c_s = c2_b_s;
          c2_b_t1 = c2_n_a;
          c2_b_f = c2_m_b;
          c2_cs = c2_d_c;
          c2_sn = c2_c_s;
          c2_f = c2_b_f;
          c2_s[c2_c_k - 1] = c2_b_t1;
          if (c2_c_k > c2_b_q + 1) {
            c2_f = -c2_sn * c2_e[0];
            c2_e[0] *= c2_cs;
          }

          c2_colk = 3 * (c2_c_k - 1);
          c2_colm = 3 * c2_m;
          c2_b_xrot(chartInstance, c2_V, c2_colk + 1, c2_colm + 1, c2_cs, c2_sn);
        }
        break;

       case 2:
        c2_qm1 = c2_b_q - 1;
        c2_f = c2_e[c2_qm1];
        c2_e[c2_qm1] = 0.0;
        c2_st.site = &c2_ed_emlrtRSI;
        c2_g_a = c2_b_q + 1;
        c2_f_b = c2_m + 1;
        c2_i_a = c2_g_a;
        c2_h_b = c2_f_b;
        if (c2_i_a > c2_h_b) {
          c2_c_overflow = false;
        } else {
          c2_c_overflow = (c2_h_b > 2147483646);
        }

        if (c2_c_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_e_k = c2_b_q + 1; c2_e_k <= c2_m + 1; c2_e_k++) {
          c2_t1 = c2_s[c2_e_k - 1];
          c2_st.site = &c2_dd_emlrtRSI;
          c2_p_a = c2_t1;
          c2_p_b = c2_f;
          c2_a__1 = c2_p_b;
          c2_c_t1 = c2_p_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_r_a = c2_c_t1;
          c2_q_b = c2_a__1;
          c2_r_b = c2_q_b;
          c2_s_a = c2_r_a;
          c2_t_a = c2_s_a;
          c2_s_b = c2_r_b;
          c2_t_b = c2_s_b;
          c2_u_a = c2_t_a;
          c2_e_c = 0.0;
          c2_d_s = 0.0;
          drotg(&c2_u_a, &c2_t_b, &c2_e_c, &c2_d_s);
          c2_s_a = c2_u_a;
          c2_g_c = c2_e_c;
          c2_e_s = c2_d_s;
          c2_c_t1 = c2_s_a;
          c2_b_cs = c2_g_c;
          c2_b_sn = c2_e_s;
          c2_s[c2_e_k - 1] = c2_c_t1;
          c2_f = -c2_b_sn * c2_e[c2_e_k - 1];
          c2_e[c2_e_k - 1] *= c2_b_cs;
          c2_colk = 3 * (c2_e_k - 1);
          c2_colqm1 = 3 * c2_qm1;
          c2_b_xrot(chartInstance, c2_U, c2_colk + 1, c2_colqm1 + 1, c2_b_cs,
                    c2_b_sn);
        }
        break;

       case 3:
        c2_mm1 = c2_m - 1;
        c2_v_x = c2_s[c2_m];
        c2_w_x = c2_v_x;
        c2_y_x = c2_w_x;
        c2_scale = muDoubleScalarAbs(c2_y_x);
        c2_cb_x = c2_s[c2_mm1];
        c2_eb_x = c2_cb_x;
        c2_gb_x = c2_eb_x;
        c2_i_y = muDoubleScalarAbs(c2_gb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_i_y);
        c2_qb_x = c2_e[c2_mm1];
        c2_sb_x = c2_qb_x;
        c2_tb_x = c2_sb_x;
        c2_k_y = muDoubleScalarAbs(c2_tb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_k_y);
        c2_ub_x = c2_s[c2_b_q];
        c2_vb_x = c2_ub_x;
        c2_wb_x = c2_vb_x;
        c2_l_y = muDoubleScalarAbs(c2_wb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_l_y);
        c2_xb_x = c2_e[c2_b_q];
        c2_yb_x = c2_xb_x;
        c2_ac_x = c2_yb_x;
        c2_m_y = muDoubleScalarAbs(c2_ac_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_m_y);
        c2_sm = c2_s[c2_m] / c2_scale;
        c2_smm1 = c2_s[c2_mm1] / c2_scale;
        c2_emm1 = c2_e[c2_mm1] / c2_scale;
        c2_sqds = c2_s[c2_b_q] / c2_scale;
        c2_eqds = c2_e[c2_b_q] / c2_scale;
        c2_u_b = ((c2_smm1 + c2_sm) * (c2_smm1 - c2_sm) + c2_emm1 * c2_emm1) /
          2.0;
        c2_f_c = c2_sm * c2_emm1;
        c2_f_c *= c2_f_c;
        if ((c2_u_b != 0.0) || (c2_f_c != 0.0)) {
          c2_shift = c2_u_b * c2_u_b + c2_f_c;
          c2_st.site = &c2_cd_emlrtRSI;
          c2_b_sqrt(chartInstance, &c2_st, &c2_shift);
          if (c2_u_b < 0.0) {
            c2_shift = -c2_shift;
          }

          c2_shift = c2_f_c / (c2_u_b + c2_shift);
        } else {
          c2_shift = 0.0;
        }

        c2_f = (c2_sqds + c2_sm) * (c2_sqds - c2_sm) + c2_shift;
        c2_g = c2_sqds * c2_eqds;
        c2_st.site = &c2_bd_emlrtRSI;
        c2_v_a = c2_b_q + 1;
        c2_v_b = c2_mm1 + 1;
        c2_w_a = c2_v_a;
        c2_w_b = c2_v_b;
        if (c2_w_a > c2_w_b) {
          c2_e_overflow = false;
        } else {
          c2_e_overflow = (c2_w_b > 2147483646);
        }

        if (c2_e_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_g_k = c2_b_q + 1; c2_g_k <= c2_mm1 + 1; c2_g_k++) {
          c2_kp1 = c2_g_k;
          c2_st.site = &c2_ad_emlrtRSI;
          c2_x_a = c2_f;
          c2_x_b = c2_g;
          c2_a__2 = c2_x_b;
          c2_c_f = c2_x_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_y_a = c2_c_f;
          c2_y_b = c2_a__2;
          c2_ab_b = c2_y_b;
          c2_ab_a = c2_y_a;
          c2_bb_a = c2_ab_a;
          c2_bb_b = c2_ab_b;
          c2_cb_b = c2_bb_b;
          c2_cb_a = c2_bb_a;
          c2_h_c = 0.0;
          c2_f_s = 0.0;
          drotg(&c2_cb_a, &c2_cb_b, &c2_h_c, &c2_f_s);
          c2_ab_a = c2_cb_a;
          c2_i_c = c2_h_c;
          c2_g_s = c2_f_s;
          c2_c_f = c2_ab_a;
          c2_c_cs = c2_i_c;
          c2_c_sn = c2_g_s;
          if (c2_g_k > c2_b_q + 1) {
            c2_e[0] = c2_c_f;
          }

          c2_f = c2_c_cs * c2_s[c2_g_k - 1] + c2_c_sn * c2_e[c2_g_k - 1];
          c2_e[c2_g_k - 1] = c2_c_cs * c2_e[c2_g_k - 1] - c2_c_sn * c2_s[c2_g_k
            - 1];
          c2_g = c2_c_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] *= c2_c_cs;
          c2_colk = 3 * (c2_g_k - 1) + 1;
          c2_colkp1 = 3 * c2_g_k + 1;
          c2_b_xrot(chartInstance, c2_V, c2_colk, c2_colkp1, c2_c_cs, c2_c_sn);
          c2_st.site = &c2_yc_emlrtRSI;
          c2_db_a = c2_f;
          c2_db_b = c2_g;
          c2_a__3 = c2_db_b;
          c2_d_f = c2_db_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_eb_a = c2_d_f;
          c2_eb_b = c2_a__3;
          c2_fb_b = c2_eb_b;
          c2_fb_a = c2_eb_a;
          c2_gb_a = c2_fb_a;
          c2_gb_b = c2_fb_b;
          c2_hb_b = c2_gb_b;
          c2_hb_a = c2_gb_a;
          c2_j_c = 0.0;
          c2_h_s = 0.0;
          drotg(&c2_hb_a, &c2_hb_b, &c2_j_c, &c2_h_s);
          c2_fb_a = c2_hb_a;
          c2_k_c = c2_j_c;
          c2_i_s = c2_h_s;
          c2_d_f = c2_fb_a;
          c2_d_cs = c2_k_c;
          c2_d_sn = c2_i_s;
          c2_s[c2_g_k - 1] = c2_d_f;
          c2_f = c2_d_cs * c2_e[c2_g_k - 1] + c2_d_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] = -c2_d_sn * c2_e[c2_g_k - 1] + c2_d_cs * c2_s[c2_kp1];
          c2_g = c2_d_sn * c2_e[c2_kp1];
          c2_e[c2_kp1] *= c2_d_cs;
          c2_b_xrot(chartInstance, c2_U, c2_colk, c2_colkp1, c2_d_cs, c2_d_sn);
        }

        c2_e[c2_m - 1] = c2_f;
        c2_iter++;
        break;

       default:
        if (c2_s[c2_b_q] < 0.0) {
          c2_s[c2_b_q] = -c2_s[c2_b_q];
          c2_colq = 3 * c2_b_q;
          c2_st.site = &c2_xc_emlrtRSI;
          c2_h_xscal(chartInstance, &c2_st, -1.0, c2_V, c2_colq + 1);
        }

        c2_qp1 = c2_b_q + 1;
        while ((c2_b_q + 1 < 3) && (c2_s[c2_b_q] < c2_s[c2_qp1])) {
          c2_rt = c2_s[c2_b_q];
          c2_s[c2_b_q] = c2_s[c2_qp1];
          c2_s[c2_qp1] = c2_rt;
          c2_colq = 3 * c2_b_q + 1;
          c2_colqp1 = 3 * (c2_b_q + 1) + 1;
          c2_b_xswap(chartInstance, c2_V, c2_colq, c2_colqp1);
          c2_b_xswap(chartInstance, c2_U, c2_colq, c2_colqp1);
          c2_b_q = c2_qp1;
          c2_qp1++;
        }

        c2_iter = 0.0;
        c2_m--;
        break;
      }
    }
  }

  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_b_k = c2_k;
    c2_S[c2_b_k] = c2_s[c2_b_k];
  }
}

static real_T c2_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[9], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_absxk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_k;
  int32_T c2_kend;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_qd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_y = 0.0;
  c2_scale = 3.3121686421112381E-170;
  c2_a = c2_b_n - 1;
  c2_c = c2_a;
  c2_b_a = c2_c;
  c2_b_c = c2_b_a;
  c2_c_a = c2_b_ix0;
  c2_b = c2_b_c;
  c2_kend = c2_c_a + c2_b;
  c2_b_st.site = &c2_rd_emlrtRSI;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_kend;
  c2_e_a = c2_d_a;
  c2_c_b = c2_b_b;
  if (c2_e_a > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_kend; c2_k++) {
    c2_b_x = c2_x[c2_k - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static real_T c2_sqrt(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, c2_sp, &c2_b_x);
  return c2_b_x;
}

static void c2_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T
                     c2_x[9], int32_T c2_ix0, real_T c2_b_x[9])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_f_xscal(chartInstance, c2_sp, c2_n, c2_a, c2_b_x, c2_ix0);
}

static real_T c2_xdotc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[9], int32_T c2_ix0, real_T
  c2_y[9], int32_T c2_iy0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_d;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_n;
  int32_T c2_i;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_wd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_st.site = &c2_xd_emlrtRSI;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_st.site = &c2_yd_emlrtRSI;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_d = 0.0;
  c2_ix = c2_d_ix0 - 1;
  c2_iy = c2_d_iy0 - 1;
  c2_d_st.site = &c2_ae_emlrtRSI;
  c2_b = c2_d_n;
  c2_b_b = c2_b;
  if (c2_b_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_e_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
  }

  c2_i = (uint8_T)c2_d_n - 1;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_d += c2_x[c2_ix] * c2_y[c2_iy];
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 1;
    c2_iy = c2_b_a;
  }

  return c2_d;
}

static void c2_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[9],
                     int32_T c2_iy0, real_T c2_b_y[9])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  c2_g_xaxpy(chartInstance, c2_n, c2_a, c2_ix0, c2_b_y, c2_iy0);
}

static real_T c2_b_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_x[3], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_absxk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_ix0;
  int32_T c2_c_a;
  int32_T c2_k;
  int32_T c2_kend;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_qd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_ix0 = c2_ix0;
  c2_y = 0.0;
  c2_scale = 3.3121686421112381E-170;
  c2_a = c2_b_ix0 + 1;
  c2_kend = c2_a;
  c2_b_st.site = &c2_rd_emlrtRSI;
  c2_b_a = c2_b_ix0;
  c2_b = c2_kend;
  c2_c_a = c2_b_a;
  c2_b_b = c2_b;
  if (c2_c_a > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_kend; c2_k++) {
    c2_b_x = c2_x[c2_k - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static void c2_b_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T
  c2_b_x[3])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_g_xscal(chartInstance, c2_sp, c2_a, c2_b_x, c2_ix0);
}

static void c2_b_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T c2_y[3],
  int32_T c2_iy0, real_T c2_b_y[3])
{
  real_T c2_b_x[9];
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 9; c2_i1++) {
    c2_b_x[c2_i1] = c2_x[c2_i1];
  }

  c2_h_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_c_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T c2_y[9],
  int32_T c2_iy0, real_T c2_b_y[9])
{
  real_T c2_b_x[3];
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_x[c2_i1] = c2_x[c2_i1];
  }

  c2_i_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_c_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T
  c2_b_x[9])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_h_xscal(chartInstance, c2_sp, c2_a, c2_b_x, c2_ix0);
}

static void c2_xrot(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                    real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c,
                    real_T c2_s, real_T c2_b_x[9])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_b_xrot(chartInstance, c2_b_x, c2_ix0, c2_iy0, c2_c, c2_s);
}

static void c2_xswap(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T
                     c2_b_x[9])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_b_xswap(chartInstance, c2_b_x, c2_ix0, c2_iy0);
}

static real_T c2_det(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                     const emlrtStack *c2_sp, real_T c2_x[9])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_g_st;
  emlrtStack c2_h_st;
  emlrtStack c2_st;
  real_T c2_b_x[9];
  real_T c2_b_k;
  real_T c2_b_temp;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_s;
  real_T c2_smax;
  real_T c2_temp;
  real_T c2_y;
  real_T c2_yjy;
  real_T c2_z;
  int32_T c2_ipiv[3];
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_i;
  int32_T c2_b_ia0;
  int32_T c2_b_ix;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_j;
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_ia0;
  int32_T c2_c_ix;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_j;
  int32_T c2_c_k;
  int32_T c2_c_m;
  int32_T c2_c_n;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_c;
  int32_T c2_d_ia0;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_k;
  int32_T c2_d_m;
  int32_T c2_d_n;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_e_k;
  int32_T c2_e_n;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_f_ix0;
  int32_T c2_f_iy0;
  int32_T c2_f_n;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_g_ix0;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_h_ix0;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_ia0;
  int32_T c2_ijA;
  int32_T c2_ix;
  int32_T c2_ix0;
  int32_T c2_iy;
  int32_T c2_iy0;
  int32_T c2_j;
  int32_T c2_jA;
  int32_T c2_j_a;
  int32_T c2_j_b;
  int32_T c2_jj;
  int32_T c2_jm1;
  int32_T c2_jp1j;
  int32_T c2_jpiv;
  int32_T c2_jpiv_offset;
  int32_T c2_jprow;
  int32_T c2_jrow;
  int32_T c2_jy;
  int32_T c2_k;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_l_a;
  int32_T c2_l_b;
  int32_T c2_m;
  int32_T c2_m_a;
  int32_T c2_m_b;
  int32_T c2_mmj;
  int32_T c2_n;
  int32_T c2_n_a;
  int32_T c2_n_b;
  int32_T c2_o_a;
  int32_T c2_o_b;
  int32_T c2_p_a;
  int32_T c2_p_b;
  int32_T c2_q_a;
  int32_T c2_r_a;
  int32_T c2_s_a;
  int32_T c2_t_a;
  int32_T c2_u_a;
  int32_T c2_v_a;
  int32_T c2_w_a;
  int32_T c2_x_a;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_isodd;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ee_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_g_st.prev = &c2_f_st;
  c2_g_st.tls = c2_f_st.tls;
  c2_h_st.prev = &c2_g_st;
  c2_h_st.tls = c2_g_st.tls;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_b_st.site = &c2_fe_emlrtRSI;
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_ipiv[c2_i1] = 1 + c2_i1;
  }

  for (c2_j = 0; c2_j < 2; c2_j++) {
    c2_b_j = c2_j + 1;
    c2_a = c2_b_j - 1;
    c2_jm1 = c2_a;
    c2_b = c2_b_j;
    c2_mmj = 3 - c2_b;
    c2_b_a = c2_jm1;
    c2_c = c2_b_a << 2;
    c2_b_b = c2_c + 1;
    c2_jj = c2_b_b;
    c2_c_a = c2_jj + 1;
    c2_jp1j = c2_c_a;
    c2_d_a = c2_mmj + 1;
    c2_b_c = c2_d_a;
    c2_n = c2_b_c;
    c2_ix0 = c2_jj;
    c2_b_n = c2_n;
    c2_b_ix0 = c2_ix0;
    c2_e_a = 0;
    c2_ix = c2_b_ix0 - 1;
    c2_c_x = c2_b_x[c2_b_ix0 - 1];
    c2_d_x = c2_c_x;
    c2_e_x = c2_d_x;
    c2_f_x = c2_e_x;
    c2_b_y = muDoubleScalarAbs(c2_f_x);
    c2_smax = c2_b_y;
    for (c2_d_k = 2; c2_d_k <= c2_b_n; c2_d_k++) {
      c2_f_a = c2_ix + 1;
      c2_ix = c2_f_a;
      c2_g_x = c2_b_x[c2_ix];
      c2_h_x = c2_g_x;
      c2_i_x = c2_h_x;
      c2_j_x = c2_i_x;
      c2_c_y = muDoubleScalarAbs(c2_j_x);
      c2_s = c2_c_y;
      if (c2_s > c2_smax) {
        c2_e_a = c2_d_k - 1;
        c2_smax = c2_s;
      }
    }

    c2_jpiv_offset = c2_e_a;
    c2_g_a = c2_jj;
    c2_c_b = c2_jpiv_offset;
    c2_jpiv = (c2_g_a + c2_c_b) - 1;
    if (c2_b_x[c2_jpiv] != 0.0) {
      if (c2_jpiv_offset != 0) {
        c2_h_a = c2_b_j;
        c2_e_b = c2_jpiv_offset;
        c2_e_c = c2_h_a + c2_e_b;
        c2_ipiv[c2_b_j - 1] = c2_e_c;
        c2_g_b = c2_jm1 + 1;
        c2_jrow = c2_g_b;
        c2_m_a = c2_jrow;
        c2_h_b = c2_jpiv_offset;
        c2_jprow = c2_m_a + c2_h_b;
        c2_d_ix0 = c2_jrow;
        c2_b_iy0 = c2_jprow;
        c2_e_ix0 = c2_d_ix0;
        c2_c_iy0 = c2_b_iy0;
        c2_b_ix = c2_e_ix0 - 1;
        c2_iy = c2_c_iy0 - 1;
        for (c2_e_k = 0; c2_e_k < 3; c2_e_k++) {
          c2_temp = c2_b_x[c2_b_ix];
          c2_b_x[c2_b_ix] = c2_b_x[c2_iy];
          c2_b_x[c2_iy] = c2_temp;
          c2_p_a = c2_b_ix + 3;
          c2_b_ix = c2_p_a;
          c2_q_a = c2_iy + 3;
          c2_iy = c2_q_a;
        }
      }

      c2_i_a = c2_mmj - 1;
      c2_d_c = c2_i_a;
      c2_k_a = c2_jp1j;
      c2_f_b = c2_d_c;
      c2_i2 = c2_k_a + c2_f_b;
      c2_c_st.site = &c2_ge_emlrtRSI;
      c2_n_a = c2_jp1j;
      c2_i_b = c2_i2;
      c2_o_a = c2_n_a;
      c2_j_b = c2_i_b;
      if (c2_o_a > c2_j_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_j_b > 2147483646);
      }

      if (c2_overflow) {
        c2_d_st.site = &c2_cc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
      }

      for (c2_b_i = c2_jp1j; c2_b_i <= c2_i2; c2_b_i++) {
        c2_k_x = c2_b_x[c2_b_i - 1];
        c2_d_y = c2_b_x[c2_jj - 1];
        c2_z = c2_k_x / c2_d_y;
        c2_b_x[c2_b_i - 1] = c2_z;
      }
    }

    c2_d_b = c2_b_j;
    c2_c_c = 3 - c2_d_b;
    c2_j_a = c2_jj + 3;
    c2_f_c = c2_j_a;
    c2_l_a = c2_jj + 4;
    c2_g_c = c2_l_a;
    c2_c_st.site = &c2_he_emlrtRSI;
    c2_m = c2_mmj;
    c2_c_n = c2_c_c;
    c2_c_ix0 = c2_jp1j;
    c2_iy0 = c2_f_c;
    c2_ia0 = c2_g_c;
    c2_d_st.site = &c2_ie_emlrtRSI;
    c2_b_m = c2_m;
    c2_d_n = c2_c_n;
    c2_f_ix0 = c2_c_ix0;
    c2_d_iy0 = c2_iy0;
    c2_b_ia0 = c2_ia0;
    c2_e_st.site = &c2_je_emlrtRSI;
    c2_c_m = c2_b_m;
    c2_e_n = c2_d_n;
    c2_g_ix0 = c2_f_ix0;
    c2_e_iy0 = c2_d_iy0;
    c2_c_ia0 = c2_b_ia0;
    c2_f_st.site = &c2_ke_emlrtRSI;
    c2_d_m = c2_c_m;
    c2_f_n = c2_e_n;
    c2_h_ix0 = c2_g_ix0;
    c2_f_iy0 = c2_e_iy0;
    c2_d_ia0 = c2_c_ia0;
    c2_r_a = c2_d_ia0 - 1;
    c2_jA = c2_r_a;
    c2_jy = c2_f_iy0;
    c2_g_st.site = &c2_me_emlrtRSI;
    c2_k_b = c2_f_n;
    c2_l_b = c2_k_b;
    if (c2_l_b < 1) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_l_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_h_st.site = &c2_cc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_h_st);
    }

    c2_i3 = (uint8_T)c2_f_n - 1;
    for (c2_c_j = 0; c2_c_j <= c2_i3; c2_c_j++) {
      c2_yjy = c2_b_x[c2_jy - 1];
      if (c2_yjy != 0.0) {
        c2_b_temp = -c2_yjy;
        c2_c_ix = c2_h_ix0 - 1;
        c2_m_b = c2_jA + 1;
        c2_i4 = c2_m_b;
        c2_u_a = c2_d_m;
        c2_n_b = c2_jA;
        c2_i5 = c2_u_a + c2_n_b;
        c2_g_st.site = &c2_le_emlrtRSI;
        c2_v_a = c2_i4;
        c2_o_b = c2_i5;
        c2_w_a = c2_v_a;
        c2_p_b = c2_o_b;
        if (c2_w_a > c2_p_b) {
          c2_c_overflow = false;
        } else {
          c2_c_overflow = (c2_p_b > 2147483646);
        }

        if (c2_c_overflow) {
          c2_h_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_h_st);
        }

        for (c2_ijA = c2_i4; c2_ijA <= c2_i5; c2_ijA++) {
          c2_b_x[c2_ijA - 1] += c2_b_x[c2_c_ix] * c2_b_temp;
          c2_x_a = c2_c_ix + 1;
          c2_c_ix = c2_x_a;
        }
      }

      c2_s_a = c2_jy + 3;
      c2_jy = c2_s_a;
      c2_t_a = c2_jA + 3;
      c2_jA = c2_t_a;
    }
  }

  c2_y = c2_b_x[0];
  for (c2_k = 0; c2_k < 2; c2_k++) {
    c2_b_k = (real_T)c2_k + 2.0;
    c2_y *= c2_b_x[((int32_T)c2_b_k + 3 * ((int32_T)c2_b_k - 1)) - 1];
  }

  c2_isodd = false;
  for (c2_c_k = 0; c2_c_k < 2; c2_c_k++) {
    c2_b_k = (real_T)c2_c_k + 1.0;
    if ((real_T)c2_ipiv[(int32_T)c2_b_k - 1] > c2_b_k) {
      c2_isodd = !c2_isodd;
    }
  }

  if (c2_isodd) {
    c2_y = -c2_y;
  }

  return c2_y;
}

static real_T c2_norm(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T c2_x[9])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_A[9];
  real_T c2_s[3];
  real_T c2_absx;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_y;
  int32_T c2_b_i;
  int32_T c2_b_j;
  int32_T c2_c_i;
  int32_T c2_i;
  int32_T c2_j;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ne_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_y = 0.0;
  for (c2_j = 0; c2_j < 3; c2_j++) {
    c2_b_j = c2_j;
    for (c2_i = 0; c2_i < 3; c2_i++) {
      c2_b_i = c2_i;
      c2_e_x = c2_x[c2_b_i + 3 * c2_b_j];
      c2_f_x = c2_e_x;
      c2_g_x = c2_f_x;
      c2_absx = muDoubleScalarAbs(c2_g_x);
      c2_h_x = c2_absx;
      c2_e_b = muDoubleScalarIsNaN(c2_h_x);
      if (c2_e_b || (c2_absx > c2_y)) {
        c2_y = c2_absx;
      }
    }
  }

  c2_b_x = c2_y;
  c2_c_x = c2_b_x;
  c2_b = muDoubleScalarIsInf(c2_c_x);
  c2_b_b = !c2_b;
  c2_d_x = c2_b_x;
  c2_c_b = muDoubleScalarIsNaN(c2_d_x);
  c2_b1 = !c2_c_b;
  c2_d_b = (c2_b_b && c2_b1);
  if (c2_d_b) {
    c2_b_st.site = &c2_oe_emlrtRSI;
    c2_c_st.site = &c2_pe_emlrtRSI;
    c2_d_st.site = &c2_vc_emlrtRSI;
    for (c2_c_i = 0; c2_c_i < 9; c2_c_i++) {
      c2_A[c2_c_i] = c2_x[c2_c_i];
    }

    c2_e_st.site = &c2_wc_emlrtRSI;
    c2_b_xzsvdc(chartInstance, &c2_e_st, c2_A, c2_s);
    c2_y = c2_s[0];
  }

  return c2_y;
}

static void c2_b_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_A[9], real_T c2_S[3])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_A[9];
  real_T c2_b_work[3];
  real_T c2_e[3];
  real_T c2_s[3];
  real_T c2_work[3];
  real_T c2_a;
  real_T c2_a__1;
  real_T c2_a__2;
  real_T c2_a__3;
  real_T c2_ab_a;
  real_T c2_ab_b;
  real_T c2_ab_x;
  real_T c2_absx;
  real_T c2_ac_x;
  real_T c2_b_a;
  real_T c2_b_absx;
  real_T c2_b_cs;
  real_T c2_b_d;
  real_T c2_b_f;
  real_T c2_b_s;
  real_T c2_b_sn;
  real_T c2_b_t1;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_bb_a;
  real_T c2_bb_b;
  real_T c2_bb_x;
  real_T c2_c_c;
  real_T c2_c_cs;
  real_T c2_c_f;
  real_T c2_c_s;
  real_T c2_c_sn;
  real_T c2_c_t1;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_cb_a;
  real_T c2_cb_b;
  real_T c2_cb_x;
  real_T c2_cs;
  real_T c2_d;
  real_T c2_d_c;
  real_T c2_d_cs;
  real_T c2_d_f;
  real_T c2_d_s;
  real_T c2_d_sn;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_db_a;
  real_T c2_db_b;
  real_T c2_db_x;
  real_T c2_e_b;
  real_T c2_e_c;
  real_T c2_e_s;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_eb_a;
  real_T c2_eb_b;
  real_T c2_eb_x;
  real_T c2_emm1;
  real_T c2_eqds;
  real_T c2_f;
  real_T c2_f_c;
  real_T c2_f_s;
  real_T c2_f_x;
  real_T c2_f_y;
  real_T c2_fb_a;
  real_T c2_fb_b;
  real_T c2_fb_x;
  real_T c2_g;
  real_T c2_g_a;
  real_T c2_g_c;
  real_T c2_g_s;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_gb_a;
  real_T c2_gb_x;
  real_T c2_h_b;
  real_T c2_h_c;
  real_T c2_h_s;
  real_T c2_h_x;
  real_T c2_h_y;
  real_T c2_hb_a;
  real_T c2_hb_x;
  real_T c2_i_c;
  real_T c2_i_s;
  real_T c2_i_x;
  real_T c2_i_y;
  real_T c2_ib_x;
  real_T c2_iter;
  real_T c2_j_b;
  real_T c2_j_c;
  real_T c2_j_x;
  real_T c2_j_y;
  real_T c2_jb_x;
  real_T c2_k_a;
  real_T c2_k_c;
  real_T c2_k_x;
  real_T c2_k_y;
  real_T c2_kase;
  real_T c2_kb_x;
  real_T c2_l_b;
  real_T c2_l_x;
  real_T c2_l_y;
  real_T c2_lb_x;
  real_T c2_m_b;
  real_T c2_m_x;
  real_T c2_m_y;
  real_T c2_mb_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_x;
  real_T c2_nb_x;
  real_T c2_nrm;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_o_x;
  real_T c2_ob_x;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_p_x;
  real_T c2_pb_x;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_x;
  real_T c2_qb_x;
  real_T c2_r;
  real_T c2_r_a;
  real_T c2_r_b;
  real_T c2_r_x;
  real_T c2_rb_x;
  real_T c2_rt;
  real_T c2_s_a;
  real_T c2_s_b;
  real_T c2_s_x;
  real_T c2_sb_x;
  real_T c2_scale;
  real_T c2_shift;
  real_T c2_sm;
  real_T c2_smm1;
  real_T c2_sn;
  real_T c2_snorm;
  real_T c2_sqds;
  real_T c2_t;
  real_T c2_t1;
  real_T c2_t_a;
  real_T c2_t_x;
  real_T c2_tb_x;
  real_T c2_test;
  real_T c2_test0;
  real_T c2_u_a;
  real_T c2_u_x;
  real_T c2_ub_x;
  real_T c2_v_b;
  real_T c2_v_x;
  real_T c2_vb_x;
  real_T c2_w_b;
  real_T c2_w_x;
  real_T c2_wb_x;
  real_T c2_x;
  real_T c2_x_a;
  real_T c2_x_b;
  real_T c2_x_x;
  real_T c2_xb_x;
  real_T c2_y;
  real_T c2_y_a;
  real_T c2_y_b;
  real_T c2_y_x;
  real_T c2_yb_x;
  real_T c2_ztest;
  real_T c2_ztest0;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ii;
  int32_T c2_b_ix0;
  int32_T c2_b_jj;
  int32_T c2_b_k;
  int32_T c2_b_q;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_ii;
  int32_T c2_c_jj;
  int32_T c2_c_k;
  int32_T c2_c_q;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_ii;
  int32_T c2_d_k;
  int32_T c2_e_a;
  int32_T c2_e_ii;
  int32_T c2_e_k;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_k;
  int32_T c2_g_b;
  int32_T c2_g_k;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_ii;
  int32_T c2_ix0;
  int32_T c2_j_a;
  int32_T c2_jj;
  int32_T c2_k;
  int32_T c2_k_b;
  int32_T c2_kp1;
  int32_T c2_l_a;
  int32_T c2_m;
  int32_T c2_m_a;
  int32_T c2_mm1;
  int32_T c2_n;
  int32_T c2_nmq;
  int32_T c2_nmqp1;
  int32_T c2_q;
  int32_T c2_qjj;
  int32_T c2_qm1;
  int32_T c2_qp1;
  int32_T c2_qp1jj;
  int32_T c2_qq;
  int32_T c2_qs;
  int32_T c2_t_b;
  int32_T c2_u_b;
  int32_T c2_v_a;
  int32_T c2_w_a;
  boolean_T c2_apply_transform;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_exitg2;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 3; c2_i++) {
    c2_s[c2_i] = 0.0;
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_e[c2_i1] = 0.0;
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_work[c2_i2] = 0.0;
  }

  for (c2_q = 0; c2_q < 2; c2_q++) {
    c2_b_q = c2_q;
    c2_qp1 = c2_b_q + 2;
    c2_qm1 = c2_b_q;
    c2_qq = (c2_b_q + 3 * c2_qm1) + 1;
    c2_nmq = 2 - c2_b_q;
    c2_nmqp1 = c2_nmq + 1;
    c2_apply_transform = false;
    c2_st.site = &c2_pd_emlrtRSI;
    c2_nrm = c2_xnrm2(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq);
    if (c2_nrm > 0.0) {
      c2_apply_transform = true;
      c2_absx = c2_nrm;
      c2_d = c2_A[c2_qq - 1];
      if (c2_d < 0.0) {
        c2_b_y = -c2_absx;
      } else {
        c2_b_y = c2_absx;
      }

      c2_s[c2_b_q] = c2_b_y;
      c2_st.site = &c2_od_emlrtRSI;
      c2_n = c2_nmqp1;
      c2_a = c2_s[c2_b_q];
      c2_ix0 = c2_qq;
      c2_m_x = c2_a;
      c2_o_x = c2_m_x;
      c2_q_x = c2_o_x;
      c2_e_y = muDoubleScalarAbs(c2_q_x);
      if (c2_e_y >= 1.0020841800044864E-292) {
        c2_b_st.site = &c2_sd_emlrtRSI;
        c2_f_xscal(chartInstance, &c2_b_st, c2_n, 1.0 / c2_a, c2_A, c2_ix0);
      } else {
        c2_c_a = c2_n - 1;
        c2_c = c2_c_a;
        c2_b = c2_c;
        c2_b_c = c2_b;
        c2_f_a = c2_ix0;
        c2_d_b = c2_b_c;
        c2_i5 = c2_f_a + c2_d_b;
        c2_b_st.site = &c2_td_emlrtRSI;
        c2_i_a = c2_ix0;
        c2_f_b = c2_i5;
        c2_l_a = c2_i_a;
        c2_i_b = c2_f_b;
        if (c2_l_a > c2_i_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_i_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_c_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
        }

        for (c2_e_k = c2_ix0; c2_e_k <= c2_i5; c2_e_k++) {
          c2_A[c2_e_k - 1] /= c2_a;
        }
      }

      c2_A[c2_qq - 1]++;
      c2_s[c2_b_q] = -c2_s[c2_b_q];
    } else {
      c2_s[c2_b_q] = 0.0;
    }

    for (c2_jj = c2_qp1; c2_jj < 4; c2_jj++) {
      c2_qjj = (c2_b_q + 3 * (c2_jj - 1)) + 1;
      if (c2_apply_transform) {
        c2_st.site = &c2_nd_emlrtRSI;
        c2_t = c2_xdotc(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq, c2_A,
                        c2_qjj);
        c2_t = -(c2_t / c2_A[c2_b_q + 3 * c2_b_q]);
        c2_g_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq, c2_A, c2_qjj);
      }

      c2_e[c2_jj - 1] = c2_A[c2_qjj - 1];
    }

    if (c2_b_q + 1 <= 1) {
      c2_st.site = &c2_md_emlrtRSI;
      c2_nrm = c2_b_xnrm2(chartInstance, &c2_st, c2_e, c2_qp1);
      if (c2_nrm == 0.0) {
        c2_e[0] = 0.0;
      } else {
        c2_b_absx = c2_nrm;
        c2_b_d = c2_e[c2_qp1 - 1];
        if (c2_b_d < 0.0) {
          c2_d_y = -c2_b_absx;
        } else {
          c2_d_y = c2_b_absx;
        }

        c2_e[0] = c2_d_y;
        c2_st.site = &c2_ld_emlrtRSI;
        c2_b_a = c2_e[0];
        c2_b_ix0 = c2_qp1;
        c2_x_x = c2_b_a;
        c2_ab_x = c2_x_x;
        c2_cb_x = c2_ab_x;
        c2_h_y = muDoubleScalarAbs(c2_cb_x);
        if (c2_h_y >= 1.0020841800044864E-292) {
          c2_b_st.site = &c2_sd_emlrtRSI;
          c2_g_xscal(chartInstance, &c2_b_st, 1.0 / c2_b_a, c2_e, c2_b_ix0);
        } else {
          c2_h_a = c2_b_ix0 + 1;
          c2_i6 = c2_h_a;
          c2_b_st.site = &c2_td_emlrtRSI;
          c2_j_a = c2_b_ix0;
          c2_g_b = c2_i6;
          c2_m_a = c2_j_a;
          c2_k_b = c2_g_b;
          if (c2_m_a > c2_k_b) {
            c2_c_overflow = false;
          } else {
            c2_c_overflow = (c2_k_b > 2147483646);
          }

          if (c2_c_overflow) {
            c2_c_st.site = &c2_cc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
          }

          for (c2_f_k = c2_b_ix0; c2_f_k <= c2_i6; c2_f_k++) {
            c2_e[c2_f_k - 1] /= c2_b_a;
          }
        }

        c2_e[c2_qp1 - 1]++;
        c2_e[0] = -c2_e[0];
        for (c2_e_ii = c2_qp1; c2_e_ii < 4; c2_e_ii++) {
          c2_work[c2_e_ii - 1] = 0.0;
        }

        for (c2_b_jj = c2_qp1; c2_b_jj < 4; c2_b_jj++) {
          c2_qp1jj = c2_qp1 + 3 * (c2_b_jj - 1);
          for (c2_i7 = 0; c2_i7 < 9; c2_i7++) {
            c2_b_A[c2_i7] = c2_A[c2_i7];
          }

          c2_h_xaxpy(chartInstance, c2_nmq, c2_e[c2_b_jj - 1], c2_b_A, c2_qp1jj,
                     c2_work, c2_qp1);
        }

        for (c2_c_jj = c2_qp1; c2_c_jj < 4; c2_c_jj++) {
          c2_t = -c2_e[c2_c_jj - 1] / c2_e[c2_qp1 - 1];
          c2_qp1jj = c2_qp1 + 3 * (c2_c_jj - 1);
          for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
            c2_b_work[c2_i8] = c2_work[c2_i8];
          }

          c2_i_xaxpy(chartInstance, c2_nmq, c2_t, c2_b_work, c2_qp1, c2_A,
                     c2_qp1jj);
        }
      }
    }
  }

  c2_m = 2;
  c2_s[2] = c2_A[8];
  c2_e[1] = c2_A[7];
  c2_e[2] = 0.0;
  for (c2_c_q = 0; c2_c_q < 3; c2_c_q++) {
    c2_b_q = c2_c_q;
    if (c2_s[c2_b_q] != 0.0) {
      c2_x = c2_s[c2_b_q];
      c2_b_x = c2_x;
      c2_d_x = c2_b_x;
      c2_rt = muDoubleScalarAbs(c2_d_x);
      c2_r = c2_s[c2_b_q] / c2_rt;
      c2_s[c2_b_q] = c2_rt;
      if (c2_b_q + 1 < 3) {
        c2_e[c2_b_q] /= c2_r;
      }
    }

    if ((c2_b_q + 1 < 3) && (c2_e[c2_b_q] != 0.0)) {
      c2_c_x = c2_e[c2_b_q];
      c2_f_x = c2_c_x;
      c2_h_x = c2_f_x;
      c2_rt = muDoubleScalarAbs(c2_h_x);
      c2_r = c2_rt / c2_e[c2_b_q];
      c2_e[c2_b_q] = c2_rt;
      c2_s[c2_b_q + 1] *= c2_r;
    }
  }

  c2_iter = 0.0;
  c2_snorm = 0.0;
  for (c2_ii = 0; c2_ii < 3; c2_ii++) {
    c2_b_ii = c2_ii;
    c2_e_x = c2_s[c2_b_ii];
    c2_g_x = c2_e_x;
    c2_i_x = c2_g_x;
    c2_y = muDoubleScalarAbs(c2_i_x);
    c2_j_x = c2_e[c2_b_ii];
    c2_k_x = c2_j_x;
    c2_l_x = c2_k_x;
    c2_c_y = muDoubleScalarAbs(c2_l_x);
    c2_snorm = muDoubleScalarMax(c2_snorm, muDoubleScalarMax(c2_y, c2_c_y));
  }

  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_m + 1 > 0)) {
    if (c2_iter >= 75.0) {
      sf_mex_call(c2_sp, &c2_h_emlrtMCI, "error", 0U, 2U, 14,
                  c2_emlrt_marshallOut(chartInstance, c2_cv5), 14, sf_mex_call
                  (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
        "message", 1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv5))));
      c2_exitg1 = true;
    } else {
      c2_b_q = c2_m;
      c2_i3 = c2_m;
      c2_c_ii = c2_i3;
      c2_exitg2 = false;
      while ((!c2_exitg2) && (c2_c_ii > -1)) {
        c2_b_q = c2_c_ii;
        if (c2_c_ii == 0) {
          c2_exitg2 = true;
        } else {
          c2_n_x = c2_s[c2_c_ii - 1];
          c2_p_x = c2_n_x;
          c2_r_x = c2_p_x;
          c2_f_y = muDoubleScalarAbs(c2_r_x);
          c2_u_x = c2_s[c2_c_ii];
          c2_w_x = c2_u_x;
          c2_y_x = c2_w_x;
          c2_g_y = muDoubleScalarAbs(c2_y_x);
          c2_test0 = c2_f_y + c2_g_y;
          c2_hb_x = c2_e[c2_c_ii - 1];
          c2_kb_x = c2_hb_x;
          c2_nb_x = c2_kb_x;
          c2_ztest0 = muDoubleScalarAbs(c2_nb_x);
          if ((c2_ztest0 <= 2.2204460492503131E-16 * c2_test0) || (c2_ztest0 <=
               1.0020841800044864E-292) || ((c2_iter > 20.0) && (c2_ztest0 <=
                2.2204460492503131E-16 * c2_snorm))) {
            c2_e[c2_c_ii - 1] = 0.0;
            c2_exitg2 = true;
          } else {
            c2_c_ii--;
          }
        }
      }

      if (c2_b_q == c2_m) {
        c2_kase = 4.0;
      } else {
        c2_qs = c2_m + 1;
        c2_d_ii = c2_m + 1;
        c2_exitg2 = false;
        while ((!c2_exitg2) && (c2_d_ii >= c2_b_q)) {
          c2_qs = c2_d_ii;
          if (c2_d_ii == c2_b_q) {
            c2_exitg2 = true;
          } else {
            c2_test = 0.0;
            if (c2_d_ii < c2_m + 1) {
              c2_db_x = c2_e[c2_d_ii - 1];
              c2_fb_x = c2_db_x;
              c2_jb_x = c2_fb_x;
              c2_test = muDoubleScalarAbs(c2_jb_x);
            }

            if (c2_d_ii > c2_b_q + 1) {
              c2_ib_x = c2_e[c2_d_ii - 2];
              c2_mb_x = c2_ib_x;
              c2_pb_x = c2_mb_x;
              c2_j_y = muDoubleScalarAbs(c2_pb_x);
              c2_test += c2_j_y;
            }

            c2_lb_x = c2_s[c2_d_ii - 1];
            c2_ob_x = c2_lb_x;
            c2_rb_x = c2_ob_x;
            c2_ztest = muDoubleScalarAbs(c2_rb_x);
            if ((c2_ztest <= 2.2204460492503131E-16 * c2_test) || (c2_ztest <=
                 1.0020841800044864E-292)) {
              c2_s[c2_d_ii - 1] = 0.0;
              c2_exitg2 = true;
            } else {
              c2_d_ii--;
            }
          }
        }

        if (c2_qs == c2_b_q) {
          c2_kase = 3.0;
        } else if (c2_qs == c2_m + 1) {
          c2_kase = 1.0;
        } else {
          c2_kase = 2.0;
          c2_b_q = c2_qs;
        }
      }

      switch ((int32_T)c2_kase) {
       case 1:
        c2_f = c2_e[c2_m - 1];
        c2_e[c2_m - 1] = 0.0;
        c2_i4 = c2_m;
        for (c2_c_k = c2_i4; c2_c_k >= c2_b_q + 1; c2_c_k--) {
          c2_t1 = c2_s[c2_c_k - 1];
          c2_st.site = &c2_fd_emlrtRSI;
          c2_g_a = c2_t1;
          c2_e_b = c2_f;
          c2_b_f = c2_e_b;
          c2_b_t1 = c2_g_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_k_a = c2_b_t1;
          c2_h_b = c2_b_f;
          c2_j_b = c2_h_b;
          c2_n_a = c2_k_a;
          c2_o_a = c2_n_a;
          c2_l_b = c2_j_b;
          c2_m_b = c2_l_b;
          c2_q_a = c2_o_a;
          c2_c_c = 0.0;
          c2_b_s = 0.0;
          drotg(&c2_q_a, &c2_m_b, &c2_c_c, &c2_b_s);
          c2_n_a = c2_q_a;
          c2_j_b = c2_m_b;
          c2_d_c = c2_c_c;
          c2_c_s = c2_b_s;
          c2_b_t1 = c2_n_a;
          c2_b_f = c2_j_b;
          c2_cs = c2_d_c;
          c2_sn = c2_c_s;
          c2_f = c2_b_f;
          c2_s[c2_c_k - 1] = c2_b_t1;
          if (c2_c_k > c2_b_q + 1) {
            c2_f = -c2_sn * c2_e[0];
            c2_e[0] *= c2_cs;
          }
        }
        break;

       case 2:
        c2_qm1 = c2_b_q - 1;
        c2_f = c2_e[c2_qm1];
        c2_e[c2_qm1] = 0.0;
        c2_st.site = &c2_ed_emlrtRSI;
        c2_d_a = c2_b_q + 1;
        c2_b_b = c2_m + 1;
        c2_e_a = c2_d_a;
        c2_c_b = c2_b_b;
        if (c2_e_a > c2_c_b) {
          c2_overflow = false;
        } else {
          c2_overflow = (c2_c_b > 2147483646);
        }

        if (c2_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_d_k = c2_b_q + 1; c2_d_k <= c2_m + 1; c2_d_k++) {
          c2_t1 = c2_s[c2_d_k - 1];
          c2_st.site = &c2_dd_emlrtRSI;
          c2_p_a = c2_t1;
          c2_n_b = c2_f;
          c2_a__1 = c2_n_b;
          c2_c_t1 = c2_p_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_r_a = c2_c_t1;
          c2_o_b = c2_a__1;
          c2_p_b = c2_o_b;
          c2_s_a = c2_r_a;
          c2_t_a = c2_s_a;
          c2_q_b = c2_p_b;
          c2_r_b = c2_q_b;
          c2_u_a = c2_t_a;
          c2_e_c = 0.0;
          c2_d_s = 0.0;
          drotg(&c2_u_a, &c2_r_b, &c2_e_c, &c2_d_s);
          c2_s_a = c2_u_a;
          c2_g_c = c2_e_c;
          c2_e_s = c2_d_s;
          c2_c_t1 = c2_s_a;
          c2_b_cs = c2_g_c;
          c2_b_sn = c2_e_s;
          c2_s[c2_d_k - 1] = c2_c_t1;
          c2_f = -c2_b_sn * c2_e[c2_d_k - 1];
          c2_e[c2_d_k - 1] *= c2_b_cs;
        }
        break;

       case 3:
        c2_mm1 = c2_m - 1;
        c2_s_x = c2_s[c2_m];
        c2_t_x = c2_s_x;
        c2_v_x = c2_t_x;
        c2_scale = muDoubleScalarAbs(c2_v_x);
        c2_bb_x = c2_s[c2_mm1];
        c2_eb_x = c2_bb_x;
        c2_gb_x = c2_eb_x;
        c2_i_y = muDoubleScalarAbs(c2_gb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_i_y);
        c2_qb_x = c2_e[c2_mm1];
        c2_sb_x = c2_qb_x;
        c2_tb_x = c2_sb_x;
        c2_k_y = muDoubleScalarAbs(c2_tb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_k_y);
        c2_ub_x = c2_s[c2_b_q];
        c2_vb_x = c2_ub_x;
        c2_wb_x = c2_vb_x;
        c2_l_y = muDoubleScalarAbs(c2_wb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_l_y);
        c2_xb_x = c2_e[c2_b_q];
        c2_yb_x = c2_xb_x;
        c2_ac_x = c2_yb_x;
        c2_m_y = muDoubleScalarAbs(c2_ac_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_m_y);
        c2_sm = c2_s[c2_m] / c2_scale;
        c2_smm1 = c2_s[c2_mm1] / c2_scale;
        c2_emm1 = c2_e[c2_mm1] / c2_scale;
        c2_sqds = c2_s[c2_b_q] / c2_scale;
        c2_eqds = c2_e[c2_b_q] / c2_scale;
        c2_s_b = ((c2_smm1 + c2_sm) * (c2_smm1 - c2_sm) + c2_emm1 * c2_emm1) /
          2.0;
        c2_f_c = c2_sm * c2_emm1;
        c2_f_c *= c2_f_c;
        if ((c2_s_b != 0.0) || (c2_f_c != 0.0)) {
          c2_shift = c2_s_b * c2_s_b + c2_f_c;
          c2_st.site = &c2_cd_emlrtRSI;
          c2_b_sqrt(chartInstance, &c2_st, &c2_shift);
          if (c2_s_b < 0.0) {
            c2_shift = -c2_shift;
          }

          c2_shift = c2_f_c / (c2_s_b + c2_shift);
        } else {
          c2_shift = 0.0;
        }

        c2_f = (c2_sqds + c2_sm) * (c2_sqds - c2_sm) + c2_shift;
        c2_g = c2_sqds * c2_eqds;
        c2_st.site = &c2_bd_emlrtRSI;
        c2_v_a = c2_b_q + 1;
        c2_t_b = c2_mm1 + 1;
        c2_w_a = c2_v_a;
        c2_u_b = c2_t_b;
        if (c2_w_a > c2_u_b) {
          c2_d_overflow = false;
        } else {
          c2_d_overflow = (c2_u_b > 2147483646);
        }

        if (c2_d_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_g_k = c2_b_q + 1; c2_g_k <= c2_mm1 + 1; c2_g_k++) {
          c2_kp1 = c2_g_k;
          c2_st.site = &c2_ad_emlrtRSI;
          c2_x_a = c2_f;
          c2_v_b = c2_g;
          c2_a__2 = c2_v_b;
          c2_c_f = c2_x_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_y_a = c2_c_f;
          c2_w_b = c2_a__2;
          c2_x_b = c2_w_b;
          c2_ab_a = c2_y_a;
          c2_bb_a = c2_ab_a;
          c2_y_b = c2_x_b;
          c2_ab_b = c2_y_b;
          c2_cb_a = c2_bb_a;
          c2_h_c = 0.0;
          c2_f_s = 0.0;
          drotg(&c2_cb_a, &c2_ab_b, &c2_h_c, &c2_f_s);
          c2_ab_a = c2_cb_a;
          c2_i_c = c2_h_c;
          c2_g_s = c2_f_s;
          c2_c_f = c2_ab_a;
          c2_c_cs = c2_i_c;
          c2_c_sn = c2_g_s;
          if (c2_g_k > c2_b_q + 1) {
            c2_e[0] = c2_c_f;
          }

          c2_f = c2_c_cs * c2_s[c2_g_k - 1] + c2_c_sn * c2_e[c2_g_k - 1];
          c2_e[c2_g_k - 1] = c2_c_cs * c2_e[c2_g_k - 1] - c2_c_sn * c2_s[c2_g_k
            - 1];
          c2_g = c2_c_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] *= c2_c_cs;
          c2_st.site = &c2_yc_emlrtRSI;
          c2_db_a = c2_f;
          c2_bb_b = c2_g;
          c2_a__3 = c2_bb_b;
          c2_d_f = c2_db_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_eb_a = c2_d_f;
          c2_cb_b = c2_a__3;
          c2_db_b = c2_cb_b;
          c2_fb_a = c2_eb_a;
          c2_gb_a = c2_fb_a;
          c2_eb_b = c2_db_b;
          c2_fb_b = c2_eb_b;
          c2_hb_a = c2_gb_a;
          c2_j_c = 0.0;
          c2_h_s = 0.0;
          drotg(&c2_hb_a, &c2_fb_b, &c2_j_c, &c2_h_s);
          c2_fb_a = c2_hb_a;
          c2_k_c = c2_j_c;
          c2_i_s = c2_h_s;
          c2_d_f = c2_fb_a;
          c2_d_cs = c2_k_c;
          c2_d_sn = c2_i_s;
          c2_s[c2_g_k - 1] = c2_d_f;
          c2_f = c2_d_cs * c2_e[c2_g_k - 1] + c2_d_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] = -c2_d_sn * c2_e[c2_g_k - 1] + c2_d_cs * c2_s[c2_kp1];
          c2_g = c2_d_sn * c2_e[c2_kp1];
          c2_e[c2_kp1] *= c2_d_cs;
        }

        c2_e[c2_m - 1] = c2_f;
        c2_iter++;
        break;

       default:
        if (c2_s[c2_b_q] < 0.0) {
          c2_s[c2_b_q] = -c2_s[c2_b_q];
        }

        c2_qp1 = c2_b_q + 1;
        while ((c2_b_q + 1 < 3) && (c2_s[c2_b_q] < c2_s[c2_qp1])) {
          c2_rt = c2_s[c2_b_q];
          c2_s[c2_b_q] = c2_s[c2_qp1];
          c2_s[c2_qp1] = c2_rt;
          c2_b_q = c2_qp1;
          c2_qp1++;
        }

        c2_iter = 0.0;
        c2_m--;
        break;
      }
    }
  }

  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_b_k = c2_k;
    c2_S[c2_b_k] = c2_s[c2_b_k];
  }
}

static real_T c2_b_norm(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_x[16])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_A[16];
  real_T c2_s[4];
  real_T c2_absx;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_y;
  int32_T c2_b_i;
  int32_T c2_b_j;
  int32_T c2_c_i;
  int32_T c2_i;
  int32_T c2_j;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ne_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_y = 0.0;
  for (c2_j = 0; c2_j < 4; c2_j++) {
    c2_b_j = c2_j;
    for (c2_i = 0; c2_i < 4; c2_i++) {
      c2_b_i = c2_i;
      c2_e_x = c2_x[c2_b_i + (c2_b_j << 2)];
      c2_f_x = c2_e_x;
      c2_g_x = c2_f_x;
      c2_absx = muDoubleScalarAbs(c2_g_x);
      c2_h_x = c2_absx;
      c2_e_b = muDoubleScalarIsNaN(c2_h_x);
      if (c2_e_b || (c2_absx > c2_y)) {
        c2_y = c2_absx;
      }
    }
  }

  c2_b_x = c2_y;
  c2_c_x = c2_b_x;
  c2_b = muDoubleScalarIsInf(c2_c_x);
  c2_b_b = !c2_b;
  c2_d_x = c2_b_x;
  c2_c_b = muDoubleScalarIsNaN(c2_d_x);
  c2_b1 = !c2_c_b;
  c2_d_b = (c2_b_b && c2_b1);
  if (c2_d_b) {
    c2_b_st.site = &c2_oe_emlrtRSI;
    c2_c_st.site = &c2_pe_emlrtRSI;
    c2_d_st.site = &c2_vc_emlrtRSI;
    for (c2_c_i = 0; c2_c_i < 16; c2_c_i++) {
      c2_A[c2_c_i] = c2_x[c2_c_i];
    }

    c2_e_st.site = &c2_wc_emlrtRSI;
    c2_c_xzsvdc(chartInstance, &c2_e_st, c2_A, c2_s);
    c2_y = c2_s[0];
  }

  return c2_y;
}

static void c2_c_xzsvdc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_A[16], real_T c2_S[4])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_A[16];
  real_T c2_b_work[4];
  real_T c2_e[4];
  real_T c2_s[4];
  real_T c2_work[4];
  real_T c2_a;
  real_T c2_a__1;
  real_T c2_a__2;
  real_T c2_a__3;
  real_T c2_ab_a;
  real_T c2_ab_b;
  real_T c2_ab_x;
  real_T c2_absx;
  real_T c2_ac_x;
  real_T c2_b_absx;
  real_T c2_b_cs;
  real_T c2_b_d;
  real_T c2_b_f;
  real_T c2_b_s;
  real_T c2_b_sn;
  real_T c2_b_t1;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_bb_a;
  real_T c2_bb_b;
  real_T c2_bb_x;
  real_T c2_c_a;
  real_T c2_c_cs;
  real_T c2_c_f;
  real_T c2_c_s;
  real_T c2_c_sn;
  real_T c2_c_t1;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_cb_a;
  real_T c2_cb_b;
  real_T c2_cb_x;
  real_T c2_cs;
  real_T c2_d;
  real_T c2_d_cs;
  real_T c2_d_f;
  real_T c2_d_s;
  real_T c2_d_sn;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_db_a;
  real_T c2_db_b;
  real_T c2_db_x;
  real_T c2_e_b;
  real_T c2_e_c;
  real_T c2_e_s;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_eb_a;
  real_T c2_eb_b;
  real_T c2_eb_x;
  real_T c2_emm1;
  real_T c2_eqds;
  real_T c2_f;
  real_T c2_f_c;
  real_T c2_f_s;
  real_T c2_f_x;
  real_T c2_f_y;
  real_T c2_fb_a;
  real_T c2_fb_b;
  real_T c2_fb_x;
  real_T c2_g;
  real_T c2_g_a;
  real_T c2_g_c;
  real_T c2_g_s;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_gb_a;
  real_T c2_gb_b;
  real_T c2_gb_x;
  real_T c2_h_b;
  real_T c2_h_c;
  real_T c2_h_s;
  real_T c2_h_x;
  real_T c2_h_y;
  real_T c2_hb_a;
  real_T c2_hb_b;
  real_T c2_hb_x;
  real_T c2_i_c;
  real_T c2_i_s;
  real_T c2_i_x;
  real_T c2_i_y;
  real_T c2_ib_a;
  real_T c2_ib_x;
  real_T c2_iter;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_j_c;
  real_T c2_j_x;
  real_T c2_j_y;
  real_T c2_jb_x;
  real_T c2_k_c;
  real_T c2_k_x;
  real_T c2_k_y;
  real_T c2_kase;
  real_T c2_kb_x;
  real_T c2_l_b;
  real_T c2_l_c;
  real_T c2_l_x;
  real_T c2_l_y;
  real_T c2_lb_x;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_m_c;
  real_T c2_m_x;
  real_T c2_m_y;
  real_T c2_mb_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_x;
  real_T c2_nb_x;
  real_T c2_nrm;
  real_T c2_o_a;
  real_T c2_o_x;
  real_T c2_ob_x;
  real_T c2_p_x;
  real_T c2_pb_x;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_x;
  real_T c2_qb_x;
  real_T c2_r;
  real_T c2_r_b;
  real_T c2_r_x;
  real_T c2_rb_x;
  real_T c2_rt;
  real_T c2_s_a;
  real_T c2_s_b;
  real_T c2_s_x;
  real_T c2_sb_x;
  real_T c2_scale;
  real_T c2_shift;
  real_T c2_sm;
  real_T c2_smm1;
  real_T c2_sn;
  real_T c2_snorm;
  real_T c2_sqds;
  real_T c2_t;
  real_T c2_t1;
  real_T c2_t_a;
  real_T c2_t_b;
  real_T c2_t_x;
  real_T c2_tb_x;
  real_T c2_test;
  real_T c2_test0;
  real_T c2_u_a;
  real_T c2_u_b;
  real_T c2_u_x;
  real_T c2_ub_x;
  real_T c2_v_a;
  real_T c2_v_x;
  real_T c2_vb_x;
  real_T c2_w_x;
  real_T c2_wb_x;
  real_T c2_x;
  real_T c2_x_b;
  real_T c2_x_x;
  real_T c2_xb_x;
  real_T c2_y;
  real_T c2_y_a;
  real_T c2_y_b;
  real_T c2_y_x;
  real_T c2_yb_x;
  real_T c2_ztest;
  real_T c2_ztest0;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ii;
  int32_T c2_b_ix0;
  int32_T c2_b_jj;
  int32_T c2_b_k;
  int32_T c2_b_n;
  int32_T c2_b_q;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_ii;
  int32_T c2_c_jj;
  int32_T c2_c_k;
  int32_T c2_c_q;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_c;
  int32_T c2_d_ii;
  int32_T c2_d_k;
  int32_T c2_e_a;
  int32_T c2_e_ii;
  int32_T c2_e_k;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_k;
  int32_T c2_g_b;
  int32_T c2_g_k;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_ii;
  int32_T c2_ix0;
  int32_T c2_jj;
  int32_T c2_k;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_km1;
  int32_T c2_kp1;
  int32_T c2_l_a;
  int32_T c2_m;
  int32_T c2_mm1;
  int32_T c2_n;
  int32_T c2_nmq;
  int32_T c2_nmqp1;
  int32_T c2_o_b;
  int32_T c2_p_a;
  int32_T c2_p_b;
  int32_T c2_pmq;
  int32_T c2_q;
  int32_T c2_qjj;
  int32_T c2_qm1;
  int32_T c2_qp1;
  int32_T c2_qp1jj;
  int32_T c2_qq;
  int32_T c2_qs;
  int32_T c2_r_a;
  int32_T c2_v_b;
  int32_T c2_w_a;
  int32_T c2_w_b;
  int32_T c2_x_a;
  boolean_T c2_apply_transform;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_exitg2;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_s[c2_i] = 0.0;
  }

  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_e[c2_i1] = 0.0;
  }

  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_work[c2_i2] = 0.0;
  }

  for (c2_q = 0; c2_q < 3; c2_q++) {
    c2_b_q = c2_q;
    c2_qp1 = c2_b_q + 2;
    c2_qm1 = c2_b_q;
    c2_qq = (c2_b_q + (c2_qm1 << 2)) + 1;
    c2_nmq = 3 - c2_b_q;
    c2_nmqp1 = c2_nmq + 1;
    c2_apply_transform = false;
    c2_st.site = &c2_pd_emlrtRSI;
    c2_nrm = c2_c_xnrm2(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq);
    if (c2_nrm > 0.0) {
      c2_apply_transform = true;
      c2_absx = c2_nrm;
      c2_d = c2_A[c2_qq - 1];
      if (c2_d < 0.0) {
        c2_b_y = -c2_absx;
      } else {
        c2_b_y = c2_absx;
      }

      c2_s[c2_b_q] = c2_b_y;
      c2_st.site = &c2_od_emlrtRSI;
      c2_n = c2_nmqp1;
      c2_a = c2_s[c2_b_q];
      c2_ix0 = c2_qq;
      c2_m_x = c2_a;
      c2_o_x = c2_m_x;
      c2_q_x = c2_o_x;
      c2_e_y = muDoubleScalarAbs(c2_q_x);
      if (c2_e_y >= 1.0020841800044864E-292) {
        c2_b_st.site = &c2_sd_emlrtRSI;
        c2_i_xscal(chartInstance, &c2_b_st, c2_n, 1.0 / c2_a, c2_A, c2_ix0);
      } else {
        c2_b_a = c2_n - 1;
        c2_c = c2_b_a;
        c2_b = c2_c;
        c2_b_c = c2_b;
        c2_f_a = c2_ix0;
        c2_d_b = c2_b_c;
        c2_i5 = c2_f_a + c2_d_b;
        c2_b_st.site = &c2_td_emlrtRSI;
        c2_i_a = c2_ix0;
        c2_f_b = c2_i5;
        c2_k_a = c2_i_a;
        c2_i_b = c2_f_b;
        if (c2_k_a > c2_i_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_i_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_c_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
        }

        for (c2_e_k = c2_ix0; c2_e_k <= c2_i5; c2_e_k++) {
          c2_A[c2_e_k - 1] /= c2_a;
        }
      }

      c2_A[c2_qq - 1]++;
      c2_s[c2_b_q] = -c2_s[c2_b_q];
    } else {
      c2_s[c2_b_q] = 0.0;
    }

    for (c2_jj = c2_qp1; c2_jj < 5; c2_jj++) {
      c2_qjj = (c2_b_q + ((c2_jj - 1) << 2)) + 1;
      if (c2_apply_transform) {
        c2_st.site = &c2_nd_emlrtRSI;
        c2_t = c2_b_xdotc(chartInstance, &c2_st, c2_nmqp1, c2_A, c2_qq, c2_A,
                          c2_qjj);
        c2_t = -(c2_t / c2_A[c2_b_q + (c2_b_q << 2)]);
        c2_j_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq, c2_A, c2_qjj);
      }

      c2_e[c2_jj - 1] = c2_A[c2_qjj - 1];
    }

    if (c2_b_q + 1 <= 2) {
      c2_pmq = 3 - c2_b_q;
      c2_st.site = &c2_md_emlrtRSI;
      c2_nrm = c2_d_xnrm2(chartInstance, &c2_st, c2_pmq, c2_e, c2_qp1);
      if (c2_nrm == 0.0) {
        c2_e[c2_b_q] = 0.0;
      } else {
        c2_b_absx = c2_nrm;
        c2_b_d = c2_e[c2_qp1 - 1];
        if (c2_b_d < 0.0) {
          c2_d_y = -c2_b_absx;
        } else {
          c2_d_y = c2_b_absx;
        }

        c2_e[c2_b_q] = c2_d_y;
        c2_st.site = &c2_ld_emlrtRSI;
        c2_b_n = c2_pmq;
        c2_c_a = c2_e[c2_b_q];
        c2_b_ix0 = c2_qp1;
        c2_ab_x = c2_c_a;
        c2_db_x = c2_ab_x;
        c2_hb_x = c2_db_x;
        c2_i_y = muDoubleScalarAbs(c2_hb_x);
        if (c2_i_y >= 1.0020841800044864E-292) {
          c2_b_st.site = &c2_sd_emlrtRSI;
          c2_j_xscal(chartInstance, &c2_b_st, c2_b_n, 1.0 / c2_c_a, c2_e,
                     c2_b_ix0);
        } else {
          c2_h_a = c2_b_n - 1;
          c2_c_c = c2_h_a;
          c2_g_b = c2_c_c;
          c2_d_c = c2_g_b;
          c2_l_a = c2_b_ix0;
          c2_k_b = c2_d_c;
          c2_i6 = c2_l_a + c2_k_b;
          c2_b_st.site = &c2_td_emlrtRSI;
          c2_p_a = c2_b_ix0;
          c2_o_b = c2_i6;
          c2_r_a = c2_p_a;
          c2_p_b = c2_o_b;
          if (c2_r_a > c2_p_b) {
            c2_c_overflow = false;
          } else {
            c2_c_overflow = (c2_p_b > 2147483646);
          }

          if (c2_c_overflow) {
            c2_c_st.site = &c2_cc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
          }

          for (c2_f_k = c2_b_ix0; c2_f_k <= c2_i6; c2_f_k++) {
            c2_e[c2_f_k - 1] /= c2_c_a;
          }
        }

        c2_e[c2_qp1 - 1]++;
        c2_e[c2_b_q] = -c2_e[c2_b_q];
        for (c2_e_ii = c2_qp1; c2_e_ii < 5; c2_e_ii++) {
          c2_work[c2_e_ii - 1] = 0.0;
        }

        for (c2_b_jj = c2_qp1; c2_b_jj < 5; c2_b_jj++) {
          c2_qp1jj = c2_qp1 + ((c2_b_jj - 1) << 2);
          for (c2_i7 = 0; c2_i7 < 16; c2_i7++) {
            c2_b_A[c2_i7] = c2_A[c2_i7];
          }

          c2_k_xaxpy(chartInstance, c2_nmq, c2_e[c2_b_jj - 1], c2_b_A, c2_qp1jj,
                     c2_work, c2_qp1);
        }

        for (c2_c_jj = c2_qp1; c2_c_jj < 5; c2_c_jj++) {
          c2_t = -c2_e[c2_c_jj - 1] / c2_e[c2_qp1 - 1];
          c2_qp1jj = c2_qp1 + ((c2_c_jj - 1) << 2);
          for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
            c2_b_work[c2_i8] = c2_work[c2_i8];
          }

          c2_l_xaxpy(chartInstance, c2_nmq, c2_t, c2_b_work, c2_qp1, c2_A,
                     c2_qp1jj);
        }
      }
    }
  }

  c2_m = 3;
  c2_s[3] = c2_A[15];
  c2_e[2] = c2_A[14];
  c2_e[3] = 0.0;
  for (c2_c_q = 0; c2_c_q < 4; c2_c_q++) {
    c2_b_q = c2_c_q;
    if (c2_s[c2_b_q] != 0.0) {
      c2_x = c2_s[c2_b_q];
      c2_b_x = c2_x;
      c2_d_x = c2_b_x;
      c2_rt = muDoubleScalarAbs(c2_d_x);
      c2_r = c2_s[c2_b_q] / c2_rt;
      c2_s[c2_b_q] = c2_rt;
      if (c2_b_q + 1 < 4) {
        c2_e[c2_b_q] /= c2_r;
      }
    }

    if ((c2_b_q + 1 < 4) && (c2_e[c2_b_q] != 0.0)) {
      c2_c_x = c2_e[c2_b_q];
      c2_f_x = c2_c_x;
      c2_h_x = c2_f_x;
      c2_rt = muDoubleScalarAbs(c2_h_x);
      c2_r = c2_rt / c2_e[c2_b_q];
      c2_e[c2_b_q] = c2_rt;
      c2_s[c2_b_q + 1] *= c2_r;
    }
  }

  c2_iter = 0.0;
  c2_snorm = 0.0;
  for (c2_ii = 0; c2_ii < 4; c2_ii++) {
    c2_b_ii = c2_ii;
    c2_e_x = c2_s[c2_b_ii];
    c2_g_x = c2_e_x;
    c2_i_x = c2_g_x;
    c2_y = muDoubleScalarAbs(c2_i_x);
    c2_j_x = c2_e[c2_b_ii];
    c2_k_x = c2_j_x;
    c2_l_x = c2_k_x;
    c2_c_y = muDoubleScalarAbs(c2_l_x);
    c2_snorm = muDoubleScalarMax(c2_snorm, muDoubleScalarMax(c2_y, c2_c_y));
  }

  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_m + 1 > 0)) {
    if (c2_iter >= 75.0) {
      sf_mex_call(c2_sp, &c2_h_emlrtMCI, "error", 0U, 2U, 14,
                  c2_emlrt_marshallOut(chartInstance, c2_cv5), 14, sf_mex_call
                  (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
        "message", 1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv5))));
      c2_exitg1 = true;
    } else {
      c2_b_q = c2_m;
      c2_i3 = c2_m;
      c2_c_ii = c2_i3;
      c2_exitg2 = false;
      while ((!c2_exitg2) && (c2_c_ii > -1)) {
        c2_b_q = c2_c_ii;
        if (c2_c_ii == 0) {
          c2_exitg2 = true;
        } else {
          c2_n_x = c2_s[c2_c_ii - 1];
          c2_p_x = c2_n_x;
          c2_r_x = c2_p_x;
          c2_f_y = muDoubleScalarAbs(c2_r_x);
          c2_u_x = c2_s[c2_c_ii];
          c2_w_x = c2_u_x;
          c2_x_x = c2_w_x;
          c2_g_y = muDoubleScalarAbs(c2_x_x);
          c2_test0 = c2_f_y + c2_g_y;
          c2_gb_x = c2_e[c2_c_ii - 1];
          c2_kb_x = c2_gb_x;
          c2_nb_x = c2_kb_x;
          c2_ztest0 = muDoubleScalarAbs(c2_nb_x);
          if ((c2_ztest0 <= 2.2204460492503131E-16 * c2_test0) || (c2_ztest0 <=
               1.0020841800044864E-292) || ((c2_iter > 20.0) && (c2_ztest0 <=
                2.2204460492503131E-16 * c2_snorm))) {
            c2_e[c2_c_ii - 1] = 0.0;
            c2_exitg2 = true;
          } else {
            c2_c_ii--;
          }
        }
      }

      if (c2_b_q == c2_m) {
        c2_kase = 4.0;
      } else {
        c2_qs = c2_m + 1;
        c2_d_ii = c2_m + 1;
        c2_exitg2 = false;
        while ((!c2_exitg2) && (c2_d_ii >= c2_b_q)) {
          c2_qs = c2_d_ii;
          if (c2_d_ii == c2_b_q) {
            c2_exitg2 = true;
          } else {
            c2_test = 0.0;
            if (c2_d_ii < c2_m + 1) {
              c2_bb_x = c2_e[c2_d_ii - 1];
              c2_eb_x = c2_bb_x;
              c2_jb_x = c2_eb_x;
              c2_test = muDoubleScalarAbs(c2_jb_x);
            }

            if (c2_d_ii > c2_b_q + 1) {
              c2_ib_x = c2_e[c2_d_ii - 2];
              c2_mb_x = c2_ib_x;
              c2_pb_x = c2_mb_x;
              c2_j_y = muDoubleScalarAbs(c2_pb_x);
              c2_test += c2_j_y;
            }

            c2_lb_x = c2_s[c2_d_ii - 1];
            c2_ob_x = c2_lb_x;
            c2_rb_x = c2_ob_x;
            c2_ztest = muDoubleScalarAbs(c2_rb_x);
            if ((c2_ztest <= 2.2204460492503131E-16 * c2_test) || (c2_ztest <=
                 1.0020841800044864E-292)) {
              c2_s[c2_d_ii - 1] = 0.0;
              c2_exitg2 = true;
            } else {
              c2_d_ii--;
            }
          }
        }

        if (c2_qs == c2_b_q) {
          c2_kase = 3.0;
        } else if (c2_qs == c2_m + 1) {
          c2_kase = 1.0;
        } else {
          c2_kase = 2.0;
          c2_b_q = c2_qs;
        }
      }

      switch ((int32_T)c2_kase) {
       case 1:
        c2_f = c2_e[c2_m - 1];
        c2_e[c2_m - 1] = 0.0;
        c2_i4 = c2_m;
        for (c2_c_k = c2_i4; c2_c_k >= c2_b_q + 1; c2_c_k--) {
          c2_t1 = c2_s[c2_c_k - 1];
          c2_st.site = &c2_fd_emlrtRSI;
          c2_g_a = c2_t1;
          c2_e_b = c2_f;
          c2_b_f = c2_e_b;
          c2_b_t1 = c2_g_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_j_a = c2_b_t1;
          c2_h_b = c2_b_f;
          c2_j_b = c2_h_b;
          c2_m_a = c2_j_a;
          c2_n_a = c2_m_a;
          c2_l_b = c2_j_b;
          c2_m_b = c2_l_b;
          c2_q_a = c2_n_a;
          c2_e_c = 0.0;
          c2_b_s = 0.0;
          drotg(&c2_q_a, &c2_m_b, &c2_e_c, &c2_b_s);
          c2_m_a = c2_q_a;
          c2_j_b = c2_m_b;
          c2_f_c = c2_e_c;
          c2_c_s = c2_b_s;
          c2_b_t1 = c2_m_a;
          c2_b_f = c2_j_b;
          c2_cs = c2_f_c;
          c2_sn = c2_c_s;
          c2_f = c2_b_f;
          c2_s[c2_c_k - 1] = c2_b_t1;
          if (c2_c_k > c2_b_q + 1) {
            c2_km1 = c2_c_k - 2;
            c2_f = -c2_sn * c2_e[c2_km1];
            c2_e[c2_km1] *= c2_cs;
          }
        }
        break;

       case 2:
        c2_qm1 = c2_b_q - 1;
        c2_f = c2_e[c2_qm1];
        c2_e[c2_qm1] = 0.0;
        c2_st.site = &c2_ed_emlrtRSI;
        c2_d_a = c2_b_q + 1;
        c2_b_b = c2_m + 1;
        c2_e_a = c2_d_a;
        c2_c_b = c2_b_b;
        if (c2_e_a > c2_c_b) {
          c2_overflow = false;
        } else {
          c2_overflow = (c2_c_b > 2147483646);
        }

        if (c2_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_d_k = c2_b_q + 1; c2_d_k <= c2_m + 1; c2_d_k++) {
          c2_t1 = c2_s[c2_d_k - 1];
          c2_st.site = &c2_dd_emlrtRSI;
          c2_o_a = c2_t1;
          c2_n_b = c2_f;
          c2_a__1 = c2_n_b;
          c2_c_t1 = c2_o_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_s_a = c2_c_t1;
          c2_q_b = c2_a__1;
          c2_r_b = c2_q_b;
          c2_t_a = c2_s_a;
          c2_u_a = c2_t_a;
          c2_s_b = c2_r_b;
          c2_t_b = c2_s_b;
          c2_v_a = c2_u_a;
          c2_g_c = 0.0;
          c2_d_s = 0.0;
          drotg(&c2_v_a, &c2_t_b, &c2_g_c, &c2_d_s);
          c2_t_a = c2_v_a;
          c2_i_c = c2_g_c;
          c2_e_s = c2_d_s;
          c2_c_t1 = c2_t_a;
          c2_b_cs = c2_i_c;
          c2_b_sn = c2_e_s;
          c2_s[c2_d_k - 1] = c2_c_t1;
          c2_f = -c2_b_sn * c2_e[c2_d_k - 1];
          c2_e[c2_d_k - 1] *= c2_b_cs;
        }
        break;

       case 3:
        c2_mm1 = c2_m - 1;
        c2_s_x = c2_s[c2_m];
        c2_t_x = c2_s_x;
        c2_v_x = c2_t_x;
        c2_scale = muDoubleScalarAbs(c2_v_x);
        c2_y_x = c2_s[c2_mm1];
        c2_cb_x = c2_y_x;
        c2_fb_x = c2_cb_x;
        c2_h_y = muDoubleScalarAbs(c2_fb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_h_y);
        c2_qb_x = c2_e[c2_mm1];
        c2_sb_x = c2_qb_x;
        c2_tb_x = c2_sb_x;
        c2_k_y = muDoubleScalarAbs(c2_tb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_k_y);
        c2_ub_x = c2_s[c2_b_q];
        c2_vb_x = c2_ub_x;
        c2_wb_x = c2_vb_x;
        c2_l_y = muDoubleScalarAbs(c2_wb_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_l_y);
        c2_xb_x = c2_e[c2_b_q];
        c2_yb_x = c2_xb_x;
        c2_ac_x = c2_yb_x;
        c2_m_y = muDoubleScalarAbs(c2_ac_x);
        c2_scale = muDoubleScalarMax(c2_scale, c2_m_y);
        c2_sm = c2_s[c2_m] / c2_scale;
        c2_smm1 = c2_s[c2_mm1] / c2_scale;
        c2_emm1 = c2_e[c2_mm1] / c2_scale;
        c2_sqds = c2_s[c2_b_q] / c2_scale;
        c2_eqds = c2_e[c2_b_q] / c2_scale;
        c2_u_b = ((c2_smm1 + c2_sm) * (c2_smm1 - c2_sm) + c2_emm1 * c2_emm1) /
          2.0;
        c2_h_c = c2_sm * c2_emm1;
        c2_h_c *= c2_h_c;
        if ((c2_u_b != 0.0) || (c2_h_c != 0.0)) {
          c2_shift = c2_u_b * c2_u_b + c2_h_c;
          c2_st.site = &c2_cd_emlrtRSI;
          c2_b_sqrt(chartInstance, &c2_st, &c2_shift);
          if (c2_u_b < 0.0) {
            c2_shift = -c2_shift;
          }

          c2_shift = c2_h_c / (c2_u_b + c2_shift);
        } else {
          c2_shift = 0.0;
        }

        c2_f = (c2_sqds + c2_sm) * (c2_sqds - c2_sm) + c2_shift;
        c2_g = c2_sqds * c2_eqds;
        c2_st.site = &c2_bd_emlrtRSI;
        c2_w_a = c2_b_q + 1;
        c2_v_b = c2_mm1 + 1;
        c2_x_a = c2_w_a;
        c2_w_b = c2_v_b;
        if (c2_x_a > c2_w_b) {
          c2_d_overflow = false;
        } else {
          c2_d_overflow = (c2_w_b > 2147483646);
        }

        if (c2_d_overflow) {
          c2_b_st.site = &c2_cc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
        }

        for (c2_g_k = c2_b_q + 1; c2_g_k <= c2_mm1 + 1; c2_g_k++) {
          c2_km1 = c2_g_k - 2;
          c2_kp1 = c2_g_k;
          c2_st.site = &c2_ad_emlrtRSI;
          c2_y_a = c2_f;
          c2_x_b = c2_g;
          c2_a__2 = c2_x_b;
          c2_c_f = c2_y_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_ab_a = c2_c_f;
          c2_y_b = c2_a__2;
          c2_ab_b = c2_y_b;
          c2_bb_a = c2_ab_a;
          c2_cb_a = c2_bb_a;
          c2_bb_b = c2_ab_b;
          c2_cb_b = c2_bb_b;
          c2_db_a = c2_cb_a;
          c2_j_c = 0.0;
          c2_f_s = 0.0;
          drotg(&c2_db_a, &c2_cb_b, &c2_j_c, &c2_f_s);
          c2_bb_a = c2_db_a;
          c2_k_c = c2_j_c;
          c2_g_s = c2_f_s;
          c2_c_f = c2_bb_a;
          c2_c_cs = c2_k_c;
          c2_c_sn = c2_g_s;
          if (c2_g_k > c2_b_q + 1) {
            c2_e[c2_km1] = c2_c_f;
          }

          c2_f = c2_c_cs * c2_s[c2_g_k - 1] + c2_c_sn * c2_e[c2_g_k - 1];
          c2_e[c2_g_k - 1] = c2_c_cs * c2_e[c2_g_k - 1] - c2_c_sn * c2_s[c2_g_k
            - 1];
          c2_g = c2_c_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] *= c2_c_cs;
          c2_st.site = &c2_yc_emlrtRSI;
          c2_eb_a = c2_f;
          c2_db_b = c2_g;
          c2_a__3 = c2_db_b;
          c2_d_f = c2_eb_a;
          c2_b_st.site = &c2_be_emlrtRSI;
          c2_fb_a = c2_d_f;
          c2_eb_b = c2_a__3;
          c2_fb_b = c2_eb_b;
          c2_gb_a = c2_fb_a;
          c2_hb_a = c2_gb_a;
          c2_gb_b = c2_fb_b;
          c2_hb_b = c2_gb_b;
          c2_ib_a = c2_hb_a;
          c2_l_c = 0.0;
          c2_h_s = 0.0;
          drotg(&c2_ib_a, &c2_hb_b, &c2_l_c, &c2_h_s);
          c2_gb_a = c2_ib_a;
          c2_m_c = c2_l_c;
          c2_i_s = c2_h_s;
          c2_d_f = c2_gb_a;
          c2_d_cs = c2_m_c;
          c2_d_sn = c2_i_s;
          c2_s[c2_g_k - 1] = c2_d_f;
          c2_f = c2_d_cs * c2_e[c2_g_k - 1] + c2_d_sn * c2_s[c2_kp1];
          c2_s[c2_kp1] = -c2_d_sn * c2_e[c2_g_k - 1] + c2_d_cs * c2_s[c2_kp1];
          c2_g = c2_d_sn * c2_e[c2_kp1];
          c2_e[c2_kp1] *= c2_d_cs;
        }

        c2_e[c2_m - 1] = c2_f;
        c2_iter++;
        break;

       default:
        if (c2_s[c2_b_q] < 0.0) {
          c2_s[c2_b_q] = -c2_s[c2_b_q];
        }

        c2_qp1 = c2_b_q + 1;
        while ((c2_b_q + 1 < 4) && (c2_s[c2_b_q] < c2_s[c2_qp1])) {
          c2_rt = c2_s[c2_b_q];
          c2_s[c2_b_q] = c2_s[c2_qp1];
          c2_s[c2_qp1] = c2_rt;
          c2_b_q = c2_qp1;
          c2_qp1++;
        }

        c2_iter = 0.0;
        c2_m--;
        break;
      }
    }
  }

  for (c2_k = 0; c2_k < 4; c2_k++) {
    c2_b_k = c2_k;
    c2_S[c2_b_k] = c2_s[c2_b_k];
  }
}

static real_T c2_c_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_absxk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_k;
  int32_T c2_kend;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_qd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_y = 0.0;
  c2_scale = 3.3121686421112381E-170;
  c2_a = c2_b_n - 1;
  c2_c = c2_a;
  c2_b_a = c2_c;
  c2_b_c = c2_b_a;
  c2_c_a = c2_b_ix0;
  c2_b = c2_b_c;
  c2_kend = c2_c_a + c2_b;
  c2_b_st.site = &c2_rd_emlrtRSI;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_kend;
  c2_e_a = c2_d_a;
  c2_c_b = c2_b_b;
  if (c2_e_a > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_kend; c2_k++) {
    c2_b_x = c2_x[c2_k - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static void c2_d_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T
  c2_ix0, real_T c2_b_x[16])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_i_xscal(chartInstance, c2_sp, c2_n, c2_a, c2_b_x, c2_ix0);
}

static real_T c2_b_xdotc(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, real_T
  c2_y[16], int32_T c2_iy0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_d;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_n;
  int32_T c2_i;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_wd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_st.site = &c2_xd_emlrtRSI;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_st.site = &c2_yd_emlrtRSI;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_d = 0.0;
  c2_ix = c2_d_ix0 - 1;
  c2_iy = c2_d_iy0 - 1;
  c2_d_st.site = &c2_ae_emlrtRSI;
  c2_b = c2_d_n;
  c2_b_b = c2_b;
  if (c2_b_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_e_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
  }

  c2_i = (uint8_T)c2_d_n - 1;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_d += c2_x[c2_ix] * c2_y[c2_iy];
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 1;
    c2_iy = c2_b_a;
  }

  return c2_d;
}

static void c2_d_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0,
  real_T c2_b_y[16])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  c2_j_xaxpy(chartInstance, c2_n, c2_a, c2_ix0, c2_b_y, c2_iy0);
}

static real_T c2_d_xnrm2(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_absxk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_k;
  int32_T c2_kend;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_qd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_y = 0.0;
  c2_scale = 3.3121686421112381E-170;
  c2_a = c2_b_n - 1;
  c2_c = c2_a;
  c2_b_a = c2_c;
  c2_b_c = c2_b_a;
  c2_c_a = c2_b_ix0;
  c2_b = c2_b_c;
  c2_kend = c2_c_a + c2_b;
  c2_b_st.site = &c2_rd_emlrtRSI;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_kend;
  c2_e_a = c2_d_a;
  c2_c_b = c2_b_b;
  if (c2_e_a > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_kend; c2_k++) {
    c2_b_x = c2_x[c2_k - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static void c2_e_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T
  c2_ix0, real_T c2_b_x[4])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_b_x[c2_i] = c2_x[c2_i];
  }

  c2_j_xscal(chartInstance, c2_sp, c2_n, c2_a, c2_b_x, c2_ix0);
}

static void c2_e_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[4],
  int32_T c2_iy0, real_T c2_b_y[4])
{
  real_T c2_b_x[16];
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 16; c2_i1++) {
    c2_b_x[c2_i1] = c2_x[c2_i1];
  }

  c2_k_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_f_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_y[16],
  int32_T c2_iy0, real_T c2_b_y[16])
{
  real_T c2_b_x[4];
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_b_y[c2_i] = c2_y[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_b_x[c2_i1] = c2_x[c2_i1];
  }

  c2_l_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_x,
  c2_emxArray_int32_T *c2_idx, c2_emxArray_real_T *c2_b_x)
{
  c2_emxArray_int32_T *c2_b_idx;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_loop_ub;
  c2_i = c2_b_x->size[0] * c2_b_x->size[1] * c2_b_x->size[2];
  c2_b_x->size[0] = 4;
  c2_b_x->size[1] = 2;
  c2_b_x->size[2] = c2_x->size[2];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_b_x, c2_i,
    &c2_yb_emlrtRTEI);
  c2_loop_ub = c2_x->size[0] * c2_x->size[1] * c2_x->size[2] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_b_x->data[c2_i1] = c2_x->data[c2_i1];
  }

  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_b_idx, 2, &c2_yb_emlrtRTEI);
  c2_i2 = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = 1;
  c2_b_idx->size[1] = c2_idx->size[1];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_b_idx, c2_i2,
    &c2_yb_emlrtRTEI);
  c2_b_loop_ub = c2_idx->size[0] * c2_idx->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_b_idx->data[c2_i3] = c2_idx->data[c2_i3];
  }

  c2_c_nullAssignment(chartInstance, c2_sp, c2_b_x, c2_b_idx);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
}

static void c2_make_bitarray(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_n, c2_emxArray_int32_T
  *c2_idx, c2_emxArray_boolean_T *c2_b)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_c_b;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_k;
  int32_T c2_loop_ub;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_i = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0] = 1;
  c2_b->size[1] = c2_n;
  c2_st.site = &c2_ng_emlrtRSI;
  c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_b, c2_i,
    &c2_ac_emlrtRTEI);
  c2_loop_ub = c2_n - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_b->data[c2_i1] = false;
  }

  c2_i2 = c2_idx->size[1];
  c2_st.site = &c2_jf_emlrtRSI;
  c2_b_b = c2_i2;
  c2_c_b = c2_b_b;
  if (c2_c_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_b_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
  }

  for (c2_k = 0; c2_k < c2_i2; c2_k++) {
    c2_b_k = c2_k;
    c2_b->data[c2_idx->data[c2_b_k] - 1] = true;
  }
}

static int32_T c2_num_true(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_b)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_c_b;
  int32_T c2_i;
  int32_T c2_k;
  int32_T c2_n;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_n = 0;
  c2_i = c2_b->size[1];
  c2_st.site = &c2_kf_emlrtRSI;
  c2_b_b = c2_i;
  c2_c_b = c2_b_b;
  if (c2_c_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_b_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
  }

  for (c2_k = 0; c2_k < c2_i; c2_k++) {
    c2_b_k = c2_k;
    c2_n += (int32_T)c2_b->data[c2_b_k];
  }

  return c2_n;
}

static void c2_b_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_x,
  c2_emxArray_int32_T *c2_idx, c2_emxArray_cell_wrap_22 *c2_b_x)
{
  c2_emxArray_int32_T *c2_b_idx;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_loop_ub;
  c2_i = c2_b_x->size[0] * c2_b_x->size[1];
  c2_b_x->size[0] = 1;
  c2_b_x->size[1] = c2_x->size[1];
  c2_emxEnsureCapacity_cell_wrap_22(chartInstance, c2_sp, c2_b_x, c2_i,
    &c2_yb_emlrtRTEI);
  c2_loop_ub = c2_x->size[0] * c2_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_emxCopyStruct_cell_wrap_22(chartInstance, c2_sp, &c2_b_x->data[c2_i1],
      &c2_x->data[c2_i1], &c2_yb_emlrtRTEI);
  }

  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_b_idx, 2, &c2_yb_emlrtRTEI);
  c2_i2 = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = 1;
  c2_b_idx->size[1] = c2_idx->size[1];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_b_idx, c2_i2,
    &c2_yb_emlrtRTEI);
  c2_b_loop_ub = c2_idx->size[0] * c2_idx->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_b_idx->data[c2_i3] = c2_idx->data[c2_i3];
  }

  c2_d_nullAssignment(chartInstance, c2_sp, c2_b_x, c2_b_idx);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
}

static void c2_OneDimArrayBehaviorTransform_parenReference
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_rigidtform3d *c2_this, c2_rigidtform3d *c2_this1)
{
  static int32_T c2_iv[2] = { 4, 4 };

  static int32_T c2_iv1[2] = { 3, 3 };

  static char_T c2_b_cv1[44] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e',
    'o', 't', 'r', 'a', 'n', 's', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r',
    'T', 'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', 'M',
    'a', 't', 'r', 'i', 'x' };

  static char_T c2_b_cv[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o',
    't', 'r', 'a', 'n', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'r',
    'a', 'n', 's', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', 'M', 'a', 't',
    'r', 'i', 'x' };

  c2_emxArray_images_geotrans_intern *c2_r;
  c2_images_geotrans_internal_rigidtform3dImpl c2_dataArray_data[1];
  c2_images_geotrans_internal_rigidtform3dImpl c2_tmp_data[1];
  c2_images_geotrans_internal_rigidtform3dImpl c2_obj;
  c2_sOEXorDAcAUBKFsVSses0uF c2_b_params;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_g_st;
  emlrtStack c2_h_st;
  emlrtStack c2_i_st;
  emlrtStack c2_j_st;
  emlrtStack c2_st;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  const mxArray *c2_p_y = NULL;
  const mxArray *c2_q_y = NULL;
  real_T c2_A_in[16];
  real_T c2_A_out[16];
  real_T c2_b_A_out[16];
  real_T c2_value[16];
  real_T c2_R[9];
  real_T c2_Rc[9];
  real_T c2_b_A_in[9];
  real_T c2_d_R[9];
  real_T c2_s[4];
  real_T c2_t[3];
  real_T c2_a;
  real_T c2_ab_x;
  real_T c2_absx;
  real_T c2_b;
  real_T c2_b_R;
  real_T c2_b_a;
  real_T c2_b_absx;
  real_T c2_b_k;
  real_T c2_b_r;
  real_T c2_b_tol;
  real_T c2_b_varargin_1;
  real_T c2_b_varargin_2;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_bb_x;
  real_T c2_c_R;
  real_T c2_c_a;
  real_T c2_c_r;
  real_T c2_c_varargin_1;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_cb_x;
  real_T c2_d_a;
  real_T c2_d_r;
  real_T c2_d_varargin_1;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_db_x;
  real_T c2_e_r;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_eb_x;
  real_T c2_f_x;
  real_T c2_fb_x;
  real_T c2_g_x;
  real_T c2_gb_x;
  real_T c2_h_x;
  real_T c2_hb_x;
  real_T c2_i_b;
  real_T c2_i_x;
  real_T c2_ib_x;
  real_T c2_j_x;
  real_T c2_jb_x;
  real_T c2_k_y;
  real_T c2_kb_x;
  real_T c2_l_x;
  real_T c2_l_y;
  real_T c2_lb_x;
  real_T c2_m_x;
  real_T c2_m_y;
  real_T c2_n_x;
  real_T c2_n_y;
  real_T c2_o_x;
  real_T c2_o_y;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_tol;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_w_x;
  real_T c2_x;
  real_T c2_x_x;
  real_T c2_y;
  real_T c2_y_x;
  int32_T c2_dataArray_size[2];
  int32_T c2_b_exponent;
  int32_T c2_b_irank;
  int32_T c2_b_loop_ub;
  int32_T c2_c_exponent;
  int32_T c2_c_k;
  int32_T c2_d_exponent;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_exponent;
  int32_T c2_f_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_irank;
  int32_T c2_k;
  int32_T c2_loop_ub;
  boolean_T c2_k_x[3];
  boolean_T c2_x_data[3];
  boolean_T c2_allFiniteA;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b_allFiniteA;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_d_p;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_g_b;
  boolean_T c2_h_b;
  boolean_T c2_h_y;
  boolean_T c2_is_affine;
  boolean_T c2_is_rotation_matrix;
  boolean_T c2_is_valid_for_this_class;
  boolean_T c2_p;
  boolean_T c2_tf;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_g_st.prev = &c2_f_st;
  c2_g_st.tls = c2_f_st.tls;
  c2_h_st.prev = &c2_g_st;
  c2_h_st.tls = c2_g_st.tls;
  c2_i_st.prev = &c2_h_st;
  c2_i_st.tls = c2_h_st.tls;
  c2_j_st.prev = &c2_i_st;
  c2_j_st.tls = c2_i_st.tls;
  c2_dataArray_size[0] = 1;
  c2_dataArray_size[1] = 1;
  c2_b_emxInit_images_geotrans_interna(chartInstance, c2_sp, &c2_r, 1,
    &c2_bc_emlrtRTEI);
  c2_i = c2_r->size[0];
  c2_r->size[0] = c2_this->Data->size[1];
  c2_st.site = &c2_mg_emlrtRSI;
  c2_b_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_r, c2_i,
    &c2_cc_emlrtRTEI);
  c2_loop_ub = c2_this->Data->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_r->data[c2_i1] = c2_this->Data->data[c2_i1];
  }

  c2_dataArray_data[0] = c2_r->data[0];
  c2_emxFree_images_geotrans_interna(chartInstance, &c2_r);
  c2_i2 = c2_this1->Data->size[0] * c2_this1->Data->size[1];
  c2_this1->Data->size[0] = 1;
  c2_this1->Data->size[1] = 1;
  c2_st.site = &c2_lg_emlrtRSI;
  c2_emxEnsureCapacity_images_geotra(chartInstance, &c2_st, c2_this1->Data,
    c2_i2, &c2_dc_emlrtRTEI);
  c2_b_loop_ub = c2_dataArray_size[0] * c2_dataArray_size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_this1->Data->data[c2_i3] = c2_dataArray_data[c2_i3];
  }

  c2_tmp_data[0] = c2_dataArray_data[0];
  c2_obj = c2_tmp_data[0];
  c2_i4 = 0;
  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
      c2_A_out[c2_i8 + c2_i4] = c2_obj.R[c2_i8 + c2_i5];
    }

    c2_i4 += 4;
    c2_i5 += 3;
  }

  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_A_out[c2_i7 + 12] = c2_obj.Translation[c2_i7];
  }

  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_A_out[c2_i9 + 3] = c2_dv[c2_i10];
    c2_i9 += 4;
  }

  c2_i11 = 0;
  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_i13 = 0;
    for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
      c2_value[c2_i14 + c2_i11] = c2_A_out[c2_i13 + c2_i12];
      c2_i13 += 4;
    }

    c2_i11 += 4;
  }

  c2_st.site = &c2_wf_emlrtRSI;
  c2_b_st.site = &c2_xf_emlrtRSI;
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    c2_i17 = 0;
    for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
      c2_A_in[c2_i18 + c2_i15] = c2_value[c2_i17 + c2_i16];
      c2_i17 += 4;
    }

    c2_i15 += 4;
  }

  c2_c_st.site = &c2_yf_emlrtRSI;
  c2_d_st.site = &c2_dg_emlrtRSI;
  c2_i19 = 0;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
      c2_b_A_in[c2_i22 + c2_i19] = c2_A_in[c2_i22 + c2_i20];
    }

    c2_i19 += 3;
    c2_i20 += 4;
  }

  c2_e_st.site = &c2_eg_emlrtRSI;
  c2_constrainToRotationMatrix3D(chartInstance, &c2_e_st, c2_b_A_in, c2_R);
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    c2_t[c2_i23] = c2_A_in[c2_i23 + 12];
  }

  c2_i24 = 0;
  c2_i25 = 0;
  for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
    for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
      c2_A_out[c2_i28 + c2_i24] = c2_R[c2_i28 + c2_i25];
    }

    c2_i24 += 4;
    c2_i25 += 3;
  }

  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    c2_A_out[c2_i27 + 12] = c2_t[c2_i27];
  }

  c2_i29 = 0;
  for (c2_i30 = 0; c2_i30 < 4; c2_i30++) {
    c2_A_out[c2_i29 + 3] = c2_dv[c2_i30];
    c2_i29 += 4;
  }

  for (c2_i31 = 0; c2_i31 < 9; c2_i31++) {
    c2_b_params.R[c2_i31] = c2_R[c2_i31];
  }

  for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
    c2_b_params.Translation[c2_i32] = c2_t[c2_i32];
  }

  c2_c_st.site = &c2_ag_emlrtRSI;
  c2_d_st.site = &c2_cf_emlrtRSI;
  c2_varargin_1 = c2_b_norm(chartInstance, &c2_d_st, c2_A_out);
  c2_d_st.site = &c2_cf_emlrtRSI;
  c2_varargin_2 = c2_b_norm(chartInstance, &c2_d_st, c2_A_in);
  c2_x = c2_varargin_1;
  c2_y = c2_varargin_2;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_x = c2_b_x;
  c2_c_y = c2_b_y;
  c2_a = c2_c_x;
  c2_b = c2_c_y;
  c2_d_x = c2_a;
  c2_d_y = c2_b;
  c2_e_x = c2_d_x;
  c2_e_y = c2_d_y;
  c2_b_R = muDoubleScalarMax(c2_e_x, c2_e_y);
  c2_b_varargin_1 = c2_b_R;
  c2_f_x = c2_b_varargin_1;
  c2_g_x = c2_f_x;
  c2_h_x = c2_g_x;
  c2_b_a = c2_h_x;
  c2_i_x = c2_b_a;
  c2_j_x = c2_i_x;
  c2_b_R = muDoubleScalarMax(c2_j_x, 1.223247290044539E-294);
  for (c2_i33 = 0; c2_i33 < 16; c2_i33++) {
    c2_b_A_out[c2_i33] = c2_A_out[c2_i33] - c2_A_in[c2_i33];
  }

  c2_d_st.site = &c2_df_emlrtRSI;
  c2_is_valid_for_this_class = (c2_b_norm(chartInstance, &c2_d_st, c2_b_A_out) /
    c2_b_R <= 1.8189894035458565E-12);
  if (!c2_is_valid_for_this_class) {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call(&c2_b_st, &c2_q_emlrtMCI, "error", 0U, 2U, 14, c2_f_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 1U, 14, c2_g_y)));
  }

  c2_c_st.site = &c2_bg_emlrtRSI;
  if (c2_A_out[15] == 1.0) {
    c2_i34 = 0;
    for (c2_i35 = 0; c2_i35 < 3; c2_i35++) {
      c2_k_x[c2_i35] = (c2_A_out[c2_i34 + 3] == 0.0);
      c2_i34 += 4;
    }

    for (c2_i36 = 0; c2_i36 < 3; c2_i36++) {
      c2_x_data[c2_i36] = c2_k_x[c2_i36];
    }

    c2_h_y = true;
    c2_k = 0;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_k < 3)) {
      c2_b_k = (real_T)c2_k + 1.0;
      if (!c2_x_data[(int32_T)c2_b_k - 1]) {
        c2_h_y = false;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }

    if (c2_h_y) {
      c2_is_affine = true;
    } else {
      c2_is_affine = false;
    }
  } else {
    c2_is_affine = false;
  }

  if (c2_is_affine) {
    c2_d_st.site = &c2_fg_emlrtRSI;
    c2_i37 = 0;
    c2_i38 = 0;
    for (c2_i39 = 0; c2_i39 < 3; c2_i39++) {
      for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
        c2_R[c2_i40 + c2_i37] = c2_A_out[c2_i40 + c2_i38];
      }

      c2_i37 += 3;
      c2_i38 += 4;
    }

    c2_e_st.site = &c2_qe_emlrtRSI;
    c2_b_irank = 0;
    c2_f_st.site = &c2_re_emlrtRSI;
    c2_g_st.site = &c2_oc_emlrtRSI;
    c2_h_st.site = &c2_rc_emlrtRSI;
    c2_i_st.site = &c2_sc_emlrtRSI;
    c2_c_p = c2_flatVectorAllOrAny(chartInstance, &c2_i_st, c2_R, c2_iv1);
    c2_d_p = !c2_c_p;
    c2_b_allFiniteA = !c2_d_p;
    if (c2_b_allFiniteA) {
      c2_g_st.site = &c2_se_emlrtRSI;
      c2_h_st.site = &c2_pe_emlrtRSI;
      c2_i_st.site = &c2_vc_emlrtRSI;
      c2_j_st.site = &c2_wc_emlrtRSI;
      c2_b_xzsvdc(chartInstance, &c2_j_st, c2_R, c2_t);
    } else {
      for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
        c2_t[c2_i42] = rtNaN;
      }
    }

    c2_q_x = c2_t[0];
    c2_r_x = c2_q_x;
    c2_t_x = c2_r_x;
    c2_v_x = c2_t_x;
    c2_w_x = c2_v_x;
    c2_b_absx = muDoubleScalarAbs(c2_w_x);
    c2_y_x = c2_b_absx;
    c2_ab_x = c2_y_x;
    c2_e_b = muDoubleScalarIsInf(c2_ab_x);
    c2_b2 = !c2_e_b;
    c2_bb_x = c2_y_x;
    c2_g_b = muDoubleScalarIsNaN(c2_bb_x);
    c2_b3 = !c2_g_b;
    c2_h_b = (c2_b2 && c2_b3);
    if (!c2_h_b) {
      c2_c_r = rtNaN;
    } else if (c2_b_absx < 4.4501477170144028E-308) {
      c2_c_r = 4.94065645841247E-324;
    } else {
      frexp(c2_b_absx, &c2_c_exponent);
      c2_d_exponent = c2_c_exponent;
      c2_c_r = ldexp(1.0, c2_d_exponent - 53);
    }

    c2_b_tol = 3.0 * c2_c_r;
    c2_e_k = 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_e_k - 1 < 3)) {
      c2_f_k = c2_e_k - 1;
      if (c2_t[c2_f_k] > c2_b_tol) {
        c2_b_irank++;
        c2_e_k++;
      } else {
        c2_exitg1 = true;
      }
    }

    c2_e_r = (real_T)c2_b_irank;
    c2_tf = (c2_e_r < 3.0);
  } else {
    c2_d_st.site = &c2_gg_emlrtRSI;
    c2_e_st.site = &c2_qe_emlrtRSI;
    c2_irank = 0;
    c2_f_st.site = &c2_re_emlrtRSI;
    c2_g_st.site = &c2_oc_emlrtRSI;
    c2_h_st.site = &c2_rc_emlrtRSI;
    c2_i_st.site = &c2_sc_emlrtRSI;
    c2_p = c2_flatVectorAllOrAny(chartInstance, &c2_i_st, c2_A_out, c2_iv);
    c2_b_p = !c2_p;
    c2_allFiniteA = !c2_b_p;
    if (c2_allFiniteA) {
      c2_g_st.site = &c2_se_emlrtRSI;
      c2_h_st.site = &c2_pe_emlrtRSI;
      c2_i_st.site = &c2_vc_emlrtRSI;
      c2_j_st.site = &c2_wc_emlrtRSI;
      c2_c_xzsvdc(chartInstance, &c2_j_st, c2_A_out, c2_s);
    } else {
      for (c2_i41 = 0; c2_i41 < 4; c2_i41++) {
        c2_s[c2_i41] = rtNaN;
      }
    }

    c2_l_x = c2_s[0];
    c2_m_x = c2_l_x;
    c2_n_x = c2_m_x;
    c2_o_x = c2_n_x;
    c2_p_x = c2_o_x;
    c2_absx = muDoubleScalarAbs(c2_p_x);
    c2_s_x = c2_absx;
    c2_u_x = c2_s_x;
    c2_b_b = muDoubleScalarIsInf(c2_u_x);
    c2_c_b = !c2_b_b;
    c2_x_x = c2_s_x;
    c2_d_b = muDoubleScalarIsNaN(c2_x_x);
    c2_b1 = !c2_d_b;
    c2_f_b = (c2_c_b && c2_b1);
    if (!c2_f_b) {
      c2_b_r = rtNaN;
    } else if (c2_absx < 4.4501477170144028E-308) {
      c2_b_r = 4.94065645841247E-324;
    } else {
      frexp(c2_absx, &c2_exponent);
      c2_b_exponent = c2_exponent;
      c2_b_r = ldexp(1.0, c2_b_exponent - 53);
    }

    c2_tol = 4.0 * c2_b_r;
    c2_c_k = 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_c_k - 1 < 4)) {
      c2_d_k = c2_c_k - 1;
      if (c2_s[c2_d_k] > c2_tol) {
        c2_irank++;
        c2_c_k++;
      } else {
        c2_exitg1 = true;
      }
    }

    c2_d_r = (real_T)c2_irank;
    c2_tf = (c2_d_r < 4.0);
  }

  if (c2_tf) {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 44),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 44),
                  false);
    sf_mex_call(&c2_b_st, &c2_r_emlrtMCI, "error", 0U, 2U, 14, c2_i_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 1U, 14, c2_j_y)));
  }

  c2_c_st.site = &c2_cg_emlrtRSI;
  c2_d_st.site = &c2_hg_emlrtRSI;
  for (c2_i43 = 0; c2_i43 < 9; c2_i43++) {
    c2_R[c2_i43] = c2_b_params.R[c2_i43];
  }

  c2_e_st.site = &c2_ye_emlrtRSI;
  c2_f_st.site = &c2_af_emlrtRSI;
  c2_constrainToRotationMatrix3D(chartInstance, &c2_f_st, c2_R, c2_Rc);
  c2_f_st.site = &c2_bf_emlrtRSI;
  c2_g_st.site = &c2_cf_emlrtRSI;
  c2_c_varargin_1 = c2_norm(chartInstance, &c2_g_st, c2_R);
  c2_g_st.site = &c2_cf_emlrtRSI;
  c2_b_varargin_2 = c2_norm(chartInstance, &c2_g_st, c2_Rc);
  c2_cb_x = c2_c_varargin_1;
  c2_k_y = c2_b_varargin_2;
  c2_db_x = c2_cb_x;
  c2_l_y = c2_k_y;
  c2_eb_x = c2_db_x;
  c2_m_y = c2_l_y;
  c2_c_a = c2_eb_x;
  c2_i_b = c2_m_y;
  c2_fb_x = c2_c_a;
  c2_n_y = c2_i_b;
  c2_gb_x = c2_fb_x;
  c2_o_y = c2_n_y;
  c2_c_R = muDoubleScalarMax(c2_gb_x, c2_o_y);
  c2_d_varargin_1 = c2_c_R;
  c2_hb_x = c2_d_varargin_1;
  c2_ib_x = c2_hb_x;
  c2_jb_x = c2_ib_x;
  c2_d_a = c2_jb_x;
  c2_kb_x = c2_d_a;
  c2_lb_x = c2_kb_x;
  c2_c_R = muDoubleScalarMax(c2_lb_x, 1.223247290044539E-294);
  for (c2_i44 = 0; c2_i44 < 9; c2_i44++) {
    c2_d_R[c2_i44] = c2_R[c2_i44] - c2_Rc[c2_i44];
  }

  c2_g_st.site = &c2_df_emlrtRSI;
  c2_is_rotation_matrix = (c2_norm(chartInstance, &c2_g_st, c2_d_R) / c2_c_R <=
    1.8189894035458565E-12);
  if (!c2_is_rotation_matrix) {
    c2_p_y = NULL;
    sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c2_q_y = NULL;
    sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    sf_mex_call(&c2_d_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_p_y, 14,
                sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_d_st, NULL, "message", 1U, 1U, 14, c2_q_y)));
  }

  for (c2_i45 = 0; c2_i45 < 9; c2_i45++) {
    c2_this1->R[c2_i45] = c2_Rc[c2_i45];
  }

  for (c2_i46 = 0; c2_i46 < 3; c2_i46++) {
    c2_t[c2_i46] = c2_b_params.Translation[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    c2_this1->Translation[c2_i47] = c2_t[c2_i47];
  }
}

static const mxArray *c2_emlrt_marshallOut
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const char_T c2_u[30])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  return c2_y;
}

static void c2_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_b_T, const char_T *c2_identifier, real_T
  c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_T), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_T);
}

static void c2_b_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_b_dv[16];
  int32_T c2_i;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_dv, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_y[c2_i] = c2_b_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CameraCalImageCapture, const
  char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_CameraCalImageCapture), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_CameraCalImageCapture);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_u;
  uint8_T c2_y;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_b_u;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_slStringInitializeDynamicBuffers
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chart_data_browse_helper(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  *c2_mxData = NULL;
  *c2_mxData = NULL;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 4U:
    *c2_isValueTooBig = 1U;
    break;

   case 5U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_T, 0, 0U,
      1U, 0U, 2, 4, 4), false);
    break;

   case 7U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_params,
      1, 0U, 1U, 0U, 2, 3, 3), false);
    break;
  }
}

static void c2_b_sqrt(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      const emlrtStack *c2_sp, real_T *c2_x)
{
  static char_T c2_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c2_b_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_x;
  boolean_T c2_b_p;
  boolean_T c2_p;
  (void)chartInstance;
  c2_b_x = *c2_x;
  if (c2_b_x < 0.0) {
    c2_p = true;
  } else {
    c2_p = false;
  }

  c2_b_p = c2_p;
  if (c2_b_p) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c2_sp, &c2_i_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_f_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T
  c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_a;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ud_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_n - 1;
  c2_c = c2_c_a;
  c2_b = c2_c;
  c2_b_c = c2_b;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_b_c;
  c2_i = c2_d_a + c2_b_b;
  c2_b_st.site = &c2_vd_emlrtRSI;
  c2_e_a = c2_b_ix0;
  c2_c_b = c2_i;
  c2_f_a = c2_e_a;
  c2_d_b = c2_c_b;
  if (c2_f_a > c2_d_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_i; c2_k++) {
    c2_x[c2_k - 1] *= c2_b_a;
  }
}

static void c2_g_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[9], int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_y[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_g_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[3], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_a;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_ix0;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ud_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_ix0 + 1;
  c2_i = c2_c_a;
  c2_b_st.site = &c2_vd_emlrtRSI;
  c2_d_a = c2_b_ix0;
  c2_b = c2_i;
  c2_e_a = c2_d_a;
  c2_b_b = c2_b;
  if (c2_e_a > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_i; c2_k++) {
    c2_x[c2_k - 1] *= c2_b_a;
  }
}

static void c2_h_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[9], int32_T c2_ix0, real_T c2_y[3],
  int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_x[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_i_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[3], int32_T c2_ix0, real_T c2_y[9],
  int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_x[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_h_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_a, real_T c2_x[9], int32_T c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_a;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_ix0;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ud_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_ix0 + 2;
  c2_i = c2_c_a;
  c2_b_st.site = &c2_vd_emlrtRSI;
  c2_d_a = c2_b_ix0;
  c2_b = c2_i;
  c2_e_a = c2_d_a;
  c2_b_b = c2_b;
  if (c2_e_a > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_i; c2_k++) {
    c2_x[c2_k - 1] *= c2_b_a;
  }
}

static void c2_b_xrot(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
                      real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0, real_T
                      c2_c, real_T c2_s)
{
  real_T c2_b_c;
  real_T c2_b_s;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_c = c2_c;
  c2_b_s = c2_s;
  c2_ix = c2_b_ix0 - 1;
  c2_iy = c2_b_iy0 - 1;
  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_temp = c2_b_c * c2_x[c2_ix] + c2_b_s * c2_x[c2_iy];
    c2_x[c2_iy] = c2_b_c * c2_x[c2_iy] - c2_b_s * c2_x[c2_ix];
    c2_x[c2_ix] = c2_temp;
    c2_a = c2_iy + 1;
    c2_iy = c2_a;
    c2_b_a = c2_ix + 1;
    c2_ix = c2_b_a;
  }
}

static void c2_b_xswap(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  real_T c2_x[9], int32_T c2_ix0, int32_T c2_iy0)
{
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_ix = c2_b_ix0 - 1;
  c2_iy = c2_b_iy0 - 1;
  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_temp = c2_x[c2_ix];
    c2_x[c2_ix] = c2_x[c2_iy];
    c2_x[c2_iy] = c2_temp;
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 1;
    c2_iy = c2_b_a;
  }
}

static void c2_i_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T
  c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_a;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ud_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_n - 1;
  c2_c = c2_c_a;
  c2_b = c2_c;
  c2_b_c = c2_b;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_b_c;
  c2_i = c2_d_a + c2_b_b;
  c2_b_st.site = &c2_vd_emlrtRSI;
  c2_e_a = c2_b_ix0;
  c2_c_b = c2_i;
  c2_f_a = c2_e_a;
  c2_d_b = c2_c_b;
  if (c2_f_a > c2_d_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_i; c2_k++) {
    c2_x[c2_k - 1] *= c2_b_a;
  }
}

static void c2_j_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_y[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_j_xscal(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T
  c2_ix0)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_a;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ud_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_n - 1;
  c2_c = c2_c_a;
  c2_b = c2_c;
  c2_b_c = c2_b;
  c2_d_a = c2_b_ix0;
  c2_b_b = c2_b_c;
  c2_i = c2_d_a + c2_b_b;
  c2_b_st.site = &c2_vd_emlrtRSI;
  c2_e_a = c2_b_ix0;
  c2_c_b = c2_i;
  c2_f_a = c2_e_a;
  c2_d_b = c2_c_b;
  if (c2_f_a > c2_d_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = c2_b_ix0; c2_k <= c2_i; c2_k++) {
    c2_x[c2_k - 1] *= c2_b_a;
  }
}

static void c2_k_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[4],
  int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_x[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_l_xaxpy(SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_y[16],
  int32_T c2_iy0)
{
  real_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_c;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i_a;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_a;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (!(c2_b_a == 0.0)) {
    c2_c_a = c2_b_ix0 - 1;
    c2_ix = c2_c_a;
    c2_d_a = c2_b_iy0 - 1;
    c2_iy = c2_d_a;
    c2_e_a = c2_b_n - 1;
    c2_i = c2_e_a;
    for (c2_k = 0; c2_k <= c2_i; c2_k++) {
      c2_f_a = c2_iy + 1;
      c2_c = c2_f_a - 1;
      c2_g_a = c2_iy + 1;
      c2_b_c = c2_g_a - 1;
      c2_h_a = c2_ix + 1;
      c2_c_c = c2_h_a - 1;
      c2_y[c2_c] = c2_y[c2_b_c] + c2_b_a * c2_x[c2_c_c];
      c2_i_a = c2_ix + 1;
      c2_ix = c2_i_a;
      c2_j_a = c2_iy + 1;
      c2_iy = c2_j_a;
    }
  }
}

static void c2_c_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_x,
  c2_emxArray_int32_T *c2_idx)
{
  c2_emxArray_boolean_T *c2_b;
  c2_emxArray_real_T *c2_b_x;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_k;
  real_T c2_d;
  real_T c2_d1;
  int32_T c2_sz[3];
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_x;
  int32_T c2_d_k;
  int32_T c2_d_x;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_ix0;
  int32_T c2_iy0;
  int32_T c2_j;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_n;
  int32_T c2_nb;
  int32_T c2_nxout;
  int32_T c2_vlen;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_ef_emlrtRSI;
  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_b_x, 3, &c2_fc_emlrtRTEI);
  c2_i = c2_b_x->size[0] * c2_b_x->size[1] * c2_b_x->size[2];
  c2_b_x->size[0] = 4;
  c2_b_x->size[1] = 2;
  c2_b_x->size[2] = c2_x->size[2];
  c2_b_st.site = &c2_ef_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_b_x, c2_i,
    &c2_fc_emlrtRTEI);
  c2_loop_ub = c2_x->size[0] * c2_x->size[1] * c2_x->size[2] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_b_x->data[c2_i1] = c2_x->data[c2_i1];
  }

  c2_n = c2_b_x->size[2];
  c2_p = true;
  c2_d = (real_T)c2_idx->size[1];
  c2_i2 = (int32_T)c2_d - 1;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k <= c2_i2)) {
    c2_b_k = (real_T)c2_k + 1.0;
    if (c2_idx->data[(int32_T)c2_b_k - 1] > c2_n) {
      c2_p = false;
      c2_exitg1 = true;
    } else {
      c2_c_x = c2_idx->data[(int32_T)c2_b_k - 1];
      c2_d_x = c2_c_x;
      if (c2_idx->data[(int32_T)c2_b_k - 1] != c2_d_x) {
        c2_p = false;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (!c2_p) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c2_st, &c2_k_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_st.site = &c2_ff_emlrtRSI;
  c2_vlen = c2_b_x->size[2];
  c2_emxInit_boolean_T(chartInstance, &c2_st, &c2_b, 2, &c2_hc_emlrtRTEI);
  c2_b_st.site = &c2_gf_emlrtRSI;
  c2_make_bitarray(chartInstance, &c2_b_st, c2_vlen, c2_idx, c2_b);
  c2_b_st.site = &c2_hf_emlrtRSI;
  c2_nxout = c2_vlen - c2_num_true(chartInstance, &c2_b_st, c2_b);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_sz[c2_i3] = c2_b_x->size[c2_i3];
  }

  if (!(c2_nxout <= c2_b_x->size[2])) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c2_st, &c2_l_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_sz[2] = c2_nxout;
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_d1 = (real_T)c2_sz[c2_i4];
    if (!(c2_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c2_d1, &c2_k_emlrtDCI, &c2_st);
    }

    c2_sz[c2_i4] = (int32_T)muDoubleScalarFloor(c2_d1);
  }

  c2_i5 = c2_x->size[0] * c2_x->size[1] * c2_x->size[2];
  c2_x->size[0] = 4;
  c2_x->size[1] = 2;
  c2_x->size[2] = c2_sz[2];
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_x, c2_i5,
    &c2_gc_emlrtRTEI);
  c2_nb = c2_b->size[1];
  c2_ix0 = -1;
  c2_iy0 = -1;
  c2_b_st.site = &c2_if_emlrtRSI;
  c2_b_b = c2_vlen;
  c2_c_b = c2_b_b;
  if (c2_c_b < 1) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_cc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_c_k = 0; c2_c_k < c2_vlen; c2_c_k++) {
    c2_d_k = c2_c_k;
    if ((c2_d_k + 1 > c2_nb) || (!c2_b->data[c2_d_k])) {
      for (c2_j = 0; c2_j < 8; c2_j++) {
        c2_b_j = c2_j + 1;
        c2_x->data[c2_iy0 + c2_b_j] = c2_b_x->data[c2_ix0 + c2_b_j];
      }

      c2_iy0 += 8;
    }

    c2_ix0 += 8;
  }

  c2_emxFree_boolean_T(chartInstance, &c2_b);
  c2_emxFree_real_T(chartInstance, &c2_b_x);
}

static void c2_d_nullAssignment(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_x,
  c2_emxArray_int32_T *c2_idx)
{
  c2_emxArray_boolean_T *c2_b_b;
  c2_emxArray_cell_wrap_22 *c2_c_x;
  c2_emxArray_cell_wrap_22 *c2_r;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_b_k;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_loop_ub;
  int32_T c2_b_x;
  int32_T c2_bidx;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_d_x;
  int32_T c2_e_b;
  int32_T c2_e_k;
  int32_T c2_f_b;
  int32_T c2_f_k;
  int32_T c2_g_b;
  int32_T c2_h_b;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_n;
  int32_T c2_nb;
  int32_T c2_nxin;
  int32_T c2_nxout;
  boolean_T c2_b;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_lf_emlrtRSI;
  c2_n = c2_x->size[1];
  c2_p = true;
  c2_d = (real_T)c2_idx->size[1];
  c2_i = (int32_T)c2_d - 1;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k <= c2_i)) {
    c2_b_k = (real_T)c2_k + 1.0;
    if (c2_idx->data[(int32_T)c2_b_k - 1] > c2_n) {
      c2_p = false;
      c2_exitg1 = true;
    } else {
      c2_b_x = c2_idx->data[(int32_T)c2_b_k - 1];
      c2_d_x = c2_b_x;
      if (c2_idx->data[(int32_T)c2_b_k - 1] != c2_d_x) {
        c2_p = false;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (!c2_p) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c2_st, &c2_m_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_st.site = &c2_qf_emlrtRSI;
  c2_emxInit_cell_wrap_22(chartInstance, &c2_st, &c2_c_x, 2, &c2_ic_emlrtRTEI);
  c2_i1 = c2_c_x->size[0] * c2_c_x->size[1];
  c2_c_x->size[0] = 1;
  c2_c_x->size[1] = c2_x->size[1];
  c2_b_st.site = &c2_kg_emlrtRSI;
  c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_b_st, c2_c_x, c2_i1,
    &c2_ic_emlrtRTEI);
  c2_loop_ub = c2_x->size[0] * c2_x->size[1] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2++) {
    c2_b_st.site = &c2_kg_emlrtRSI;
    c2_emxCopyStruct_cell_wrap_22(chartInstance, &c2_b_st, &c2_c_x->data[c2_i2],
      &c2_x->data[c2_i2], &c2_ic_emlrtRTEI);
  }

  c2_nxin = c2_c_x->size[1];
  c2_b = (c2_idx->size[1] == 1);
  c2_emxInit_cell_wrap_22(chartInstance, &c2_st, &c2_r, 2, &c2_yb_emlrtRTEI);
  if (c2_b) {
    c2_nxout = c2_nxin - 1;
    if (!(c2_nxout <= c2_nxin)) {
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c2_st, &c2_o_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                  sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
    }

    c2_i3 = c2_r->size[0] * c2_r->size[1];
    c2_r->size[0] = 1;
    c2_d1 = (real_T)c2_nxout;
    if (!(c2_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c2_d1, &c2_l_emlrtDCI, &c2_st);
    }

    c2_r->size[1] = (int32_T)muDoubleScalarFloor(c2_d1);
    c2_b_st.site = &c2_qf_emlrtRSI;
    c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_b_st, c2_r, c2_i3,
      &c2_jc_emlrtRTEI);
    c2_i5 = c2_x->size[0] * c2_x->size[1];
    c2_x->size[0] = c2_r->size[0];
    c2_x->size[1] = c2_r->size[1];
    c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_st, c2_x, c2_i5,
      &c2_kc_emlrtRTEI);
    c2_i6 = c2_idx->data[0] - 1;
    c2_i8 = muIntScalarMin_sint32(c2_i6, c2_x->size[1]);
    c2_b_st.site = &c2_rf_emlrtRSI;
    c2_c_b = c2_i8;
    c2_d_b = c2_c_b;
    if (c2_d_b < 1) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_d_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_cc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_c_k = 0; c2_c_k < c2_i8; c2_c_k++) {
      c2_d_k = c2_c_k;
      c2_i12 = c2_x->data[c2_d_k].f1->size[0] * c2_x->data[c2_d_k].f1->size[1];
      c2_x->data[c2_d_k].f1->size[0] = 1;
      c2_x->data[c2_d_k].f1->size[1] = c2_c_x->data[c2_d_k].f1->size[1];
      c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_x->data[c2_d_k].f1,
        c2_i12, &c2_lc_emlrtRTEI);
      c2_b_loop_ub = c2_c_x->data[c2_d_k].f1->size[0] * c2_c_x->data[c2_d_k].
        f1->size[1] - 1;
      for (c2_i13 = 0; c2_i13 <= c2_b_loop_ub; c2_i13++) {
        c2_x->data[c2_d_k].f1->data[c2_i13] = c2_c_x->data[c2_d_k].f1->
          data[c2_i13];
      }
    }

    c2_i10 = c2_idx->data[0];
    c2_i11 = c2_x->size[1];
    c2_b_st.site = &c2_sf_emlrtRSI;
    c2_a = c2_i10;
    c2_g_b = c2_i11;
    c2_b_a = c2_a;
    c2_h_b = c2_g_b;
    if (c2_b_a > c2_h_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_h_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_c_st.site = &c2_cc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_f_k = c2_i10; c2_f_k <= c2_i11; c2_f_k++) {
      c2_i16 = c2_x->data[c2_f_k - 1].f1->size[0] * c2_x->data[c2_f_k - 1]
        .f1->size[1];
      c2_x->data[c2_f_k - 1].f1->size[0] = 1;
      c2_x->data[c2_f_k - 1].f1->size[1] = c2_c_x->data[c2_f_k].f1->size[1];
      c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_x->data[c2_f_k - 1].
        f1, c2_i16, &c2_nc_emlrtRTEI);
      c2_d_loop_ub = c2_c_x->data[c2_f_k].f1->size[0] * c2_c_x->data[c2_f_k].
        f1->size[1] - 1;
      for (c2_i17 = 0; c2_i17 <= c2_d_loop_ub; c2_i17++) {
        c2_x->data[c2_f_k - 1].f1->data[c2_i17] = c2_c_x->data[c2_f_k].f1->
          data[c2_i17];
      }
    }
  } else {
    c2_emxInit_boolean_T(chartInstance, &c2_st, &c2_b_b, 2, &c2_oc_emlrtRTEI);
    c2_b_st.site = &c2_tf_emlrtRSI;
    c2_make_bitarray(chartInstance, &c2_b_st, c2_nxin, c2_idx, c2_b_b);
    c2_b_st.site = &c2_uf_emlrtRSI;
    c2_nxout = c2_nxin - c2_num_true(chartInstance, &c2_b_st, c2_b_b);
    c2_nb = c2_b_b->size[1];
    if (!(c2_nxout <= c2_nxin)) {
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c2_st, &c2_p_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                  sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c2_st, NULL, "message", 1U, 1U, 14, c2_f_y)));
    }

    c2_i4 = c2_r->size[0] * c2_r->size[1];
    c2_r->size[0] = 1;
    c2_d2 = (real_T)c2_nxout;
    if (!(c2_d2 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c2_d2, &c2_m_emlrtDCI, &c2_st);
    }

    c2_r->size[1] = (int32_T)muDoubleScalarFloor(c2_d2);
    c2_b_st.site = &c2_qf_emlrtRSI;
    c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_b_st, c2_r, c2_i4,
      &c2_jc_emlrtRTEI);
    c2_i7 = c2_x->size[0] * c2_x->size[1];
    c2_x->size[0] = c2_r->size[0];
    c2_x->size[1] = c2_r->size[1];
    c2_emxEnsureCapacity_cell_wrap_22(chartInstance, &c2_st, c2_x, c2_i7,
      &c2_kc_emlrtRTEI);
    c2_bidx = 0;
    c2_i9 = c2_x->size[1];
    c2_b_st.site = &c2_vf_emlrtRSI;
    c2_e_b = c2_i9;
    c2_f_b = c2_e_b;
    if (c2_f_b < 1) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_f_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_c_st.site = &c2_cc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_e_k = 0; c2_e_k < c2_i9; c2_e_k++) {
      c2_d_k = c2_e_k;
      while ((c2_bidx + 1 <= c2_nb) && c2_b_b->data[c2_bidx]) {
        c2_bidx++;
      }

      c2_i14 = c2_x->data[c2_d_k].f1->size[0] * c2_x->data[c2_d_k].f1->size[1];
      c2_x->data[c2_d_k].f1->size[0] = 1;
      c2_x->data[c2_d_k].f1->size[1] = c2_c_x->data[c2_bidx].f1->size[1];
      c2_emxEnsureCapacity_char_T(chartInstance, &c2_st, c2_x->data[c2_d_k].f1,
        c2_i14, &c2_mc_emlrtRTEI);
      c2_c_loop_ub = c2_c_x->data[c2_bidx].f1->size[0] * c2_c_x->data[c2_bidx].
        f1->size[1] - 1;
      for (c2_i15 = 0; c2_i15 <= c2_c_loop_ub; c2_i15++) {
        c2_x->data[c2_d_k].f1->data[c2_i15] = c2_c_x->data[c2_bidx].f1->
          data[c2_i15];
      }

      c2_bidx++;
    }

    c2_emxFree_boolean_T(chartInstance, &c2_b_b);
  }

  c2_emxFree_cell_wrap_22(chartInstance, &c2_r);
  c2_emxFree_cell_wrap_22(chartInstance, &c2_c_x);
}

static void c2_emxInitStruct_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cameraParameters *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInitStruct_vision_internal_c(chartInstance, c2_sp,
    &c2_pStruct->UndistortMap, c2_srcLocation);
}

static void c2_emxInitStruct_vision_internal_c
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_vision_internal_calibration_ImageTransformer *c2_pStruct, const
   emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_pStruct->SizeOfImage, 2,
                    c2_srcLocation);
  c2_emxInit_char_T(chartInstance, c2_sp, &c2_pStruct->ClassOfImage, 2,
                    c2_srcLocation);
  c2_emxInit_char_T(chartInstance, c2_sp, &c2_pStruct->OutputView, 2,
                    c2_srcLocation);
}

static void c2_emxInit_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_char_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_char_T *)emlrtMallocMex(sizeof(c2_emxArray_char_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (char_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInitStruct_rigidtform3d
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_rigidtform3d *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_images_geotrans_interna(chartInstance, c2_sp, &c2_pStruct->Data, 2,
    c2_srcLocation);
}

static void c2_emxInit_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern **c2_pEmxArray, int32_T
   c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_images_geotrans_intern *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_images_geotrans_intern *)emlrtMallocMex(sizeof
    (c2_emxArray_images_geotrans_intern));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_images_geotrans_internal_rigidtform3dImpl *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_real_T1(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real_T *)NULL;
  }
}

static void c2_emxFreeStruct_vision_internal_c
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
   c2_vision_internal_calibration_ImageTransformer *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->SizeOfImage);
  c2_emxFree_char_T(chartInstance, &c2_pStruct->ClassOfImage);
  c2_emxFree_char_T(chartInstance, &c2_pStruct->OutputView);
}

static void c2_emxFree_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_char_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_char_T *)NULL) {
    if (((*c2_pEmxArray)->data != (char_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_char_T *)NULL;
  }
}

static void c2_emxFreeStruct_cameraParameters
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_cameraParameters *
   c2_pStruct)
{
  c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_pStruct->UndistortMap);
}

static void c2_emxFree_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance,
   c2_emxArray_images_geotrans_intern **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_images_geotrans_intern *)NULL) {
    if (((*c2_pEmxArray)->data != (c2_images_geotrans_internal_rigidtform3dImpl *)
         NULL) && (*c2_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_images_geotrans_intern *)NULL;
  }
}

static void c2_emxFreeStruct_rigidtform3d
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_rigidtform3d
   *c2_pStruct)
{
  c2_emxFree_images_geotrans_interna(chartInstance, &c2_pStruct->Data);
}

static void c2_emxEnsureCapacity_real_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(char_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(char_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (char_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real_T1
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxFreeStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, c2_cell_wrap_22
   *c2_pStruct)
{
  c2_emxFree_char_T(chartInstance, &c2_pStruct->f1);
}

static void c2_emxTrim_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_cell_wrap_22 *c2_emxArray, int32_T c2_fromIndex,
  int32_T c2_toIndex)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxFreeStruct_cell_wrap_22(chartInstance, &c2_emxArray->data[c2_i]);
  }
}

static void c2_emxInitStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cell_wrap_22 *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_char_T(chartInstance, c2_sp, &c2_pStruct->f1, 2, c2_srcLocation);
}

static void c2_emxExpand_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22 *c2_emxArray,
  int32_T c2_fromIndex, int32_T c2_toIndex, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxInitStruct_cell_wrap_22(chartInstance, c2_sp, &c2_emxArray->data[c2_i],
      c2_srcLocation);
  }
}

static void c2_emxEnsureCapacity_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_cell_wrap_22 *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(c2_cell_wrap_22));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_cell_wrap_22) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_cell_wrap_22 *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }

  if (c2_oldNumel > c2_newNumel) {
    c2_emxTrim_cell_wrap_22(chartInstance, c2_emxArray, c2_newNumel, c2_oldNumel);
  } else if (c2_oldNumel < c2_newNumel) {
    c2_emxExpand_cell_wrap_22(chartInstance, c2_sp, c2_emxArray, c2_oldNumel,
      c2_newNumel, c2_srcLocation);
  }
}

static void c2_emxEnsureCapacity_images_geotra
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern *c2_emxArray, int32_T c2_oldNumel,
   const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_images_geotrans_internal_rigidtform3dImpl));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof
             (c2_images_geotrans_internal_rigidtform3dImpl) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_images_geotrans_internal_rigidtform3dImpl *)
      c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_int32_T
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_b_emxEnsureCapacity_images_geotra
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern *c2_emxArray, int32_T c2_oldNumel,
   const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_images_geotrans_internal_rigidtform3dImpl));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof
             (c2_images_geotrans_internal_rigidtform3dImpl) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_images_geotrans_internal_rigidtform3dImpl *)
      c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_cell_wrap_22
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_cell_wrap_22 *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_cell_wrap_22 *)emlrtMallocMex(sizeof
    (c2_emxArray_cell_wrap_22));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_cell_wrap_22 *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_b_emxInit_images_geotrans_interna
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_images_geotrans_intern **c2_pEmxArray, int32_T
   c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_images_geotrans_intern *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_images_geotrans_intern *)emlrtMallocMex(sizeof
    (c2_emxArray_images_geotrans_intern));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_images_geotrans_internal_rigidtform3dImpl *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_boolean_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_cell_wrap_22(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_cell_wrap_22 **c2_pEmxArray)
{
  int32_T c2_b_i;
  int32_T c2_i;
  int32_T c2_numEl;
  if (*c2_pEmxArray != (c2_emxArray_cell_wrap_22 *)NULL) {
    if ((*c2_pEmxArray)->data != (c2_cell_wrap_22 *)NULL) {
      c2_numEl = 1;
      for (c2_i = 0; c2_i < (*c2_pEmxArray)->numDimensions; c2_i++) {
        c2_numEl *= (*c2_pEmxArray)->size[c2_i];
      }

      for (c2_b_i = 0; c2_b_i < c2_numEl; c2_b_i++) {
        c2_emxFreeStruct_cell_wrap_22(chartInstance, &(*c2_pEmxArray)->
          data[c2_b_i]);
      }

      if ((*c2_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c2_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_cell_wrap_22 *)NULL;
  }
}

static void c2_emxFree_int32_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_int32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (int32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_int32_T *)NULL;
  }
}

static void c2_emxFree_boolean_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_boolean_T *)NULL) {
    if (((*c2_pEmxArray)->data != (boolean_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_boolean_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_boolean_T
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_emxArray_boolean_T *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxCopyStruct_cell_wrap_22
  (SFc2_CameraCalImageCaptureInstanceStruct *chartInstance, const emlrtStack
   *c2_sp, c2_cell_wrap_22 *c2_dst, const c2_cell_wrap_22 *c2_src, const
   emlrtRTEInfo *c2_srcLocation)
{
  c2_emxCopy_char_T(chartInstance, c2_sp, &c2_dst->f1, &c2_src->f1,
                    c2_srcLocation);
}

static void c2_emxCopy_char_T(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_char_T **c2_dst,
  c2_emxArray_char_T * const *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_char_T(chartInstance, c2_sp, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void init_dsm_address_info(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_CameraCalImageCaptureInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_image = (uint8_T (*)[307200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_T = (real_T (*)[16])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_params = (real32_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_CameraCalImageCapture_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(698968866U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1769686790U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(580677354U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3163407860U);
}

mxArray *sf_c2_CameraCalImageCapture_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "vision.internal.buildable.readAprilTagBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c2_CameraCalImageCapture_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("getAprilTagIdPoseDetections");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_CameraCalImageCapture_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_CameraCalImageCapture(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0iziA9Bsg6WchoF8AyAqBhQuUJt9+BQfK9EPsjyDgfi"
    "UU90P4mcXxicklmWWp8clG8c7ASClKdE7M8cxNTE91TiwoKS1KRZgPAgA1UhvS"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CameraCalImageCapture_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sFJg6TMxktTOc3nDpojrwRB";
}

static void sf_opaque_initialize_c2_CameraCalImageCapture(void *chartInstanceVar)
{
  initialize_params_c2_CameraCalImageCapture
    ((SFc2_CameraCalImageCaptureInstanceStruct*) chartInstanceVar);
  initialize_c2_CameraCalImageCapture((SFc2_CameraCalImageCaptureInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_CameraCalImageCapture(void *chartInstanceVar)
{
  enable_c2_CameraCalImageCapture((SFc2_CameraCalImageCaptureInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_CameraCalImageCapture(void *chartInstanceVar)
{
  disable_c2_CameraCalImageCapture((SFc2_CameraCalImageCaptureInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_CameraCalImageCapture(void *chartInstanceVar)
{
  sf_gateway_c2_CameraCalImageCapture((SFc2_CameraCalImageCaptureInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_CameraCalImageCapture(SimStruct*
  S)
{
  return get_sim_state_c2_CameraCalImageCapture
    ((SFc2_CameraCalImageCaptureInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_CameraCalImageCapture(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_CameraCalImageCapture
    ((SFc2_CameraCalImageCaptureInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_CameraCalImageCapture(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CameraCalImageCaptureInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CameraCalImageCapture_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_CameraCalImageCapture
      ((SFc2_CameraCalImageCaptureInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_CameraCalImageCapture(void *chartInstanceVar)
{
  mdl_start_c2_CameraCalImageCapture((SFc2_CameraCalImageCaptureInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c2_CameraCalImageCapture(void
  *chartInstanceVar)
{
  mdl_terminate_c2_CameraCalImageCapture
    ((SFc2_CameraCalImageCaptureInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CameraCalImageCapture
    ((SFc2_CameraCalImageCaptureInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CameraCalImageCapture(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CameraCalImageCapture
      ((SFc2_CameraCalImageCaptureInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc2_CameraCalImageCapture
      ((SFc2_CameraCalImageCaptureInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_CameraCalImageCapture_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWMuO40QUrURNixHDqBdIgITEaCQkNkjQIxALHt15QZgO3RqnG8SmVW3fxEXKVZ565IH4EL6",
    "ANTu+gx0rFvADCAnEklu2kwlOJnGlxTCDcMvtlO1T595b91UmtW6P4HELz29eJmQfr8/iWSf58U",
    "wxri2d+f098l4x/vo5QkIZwRBEYAcDNiV+h7DJGVU00cT/EDSB+6Alt4ZJ0RUDWR3LxAAUiBAnS",
    "KUyXryaJZYzMepYETpm/VnMwjiIpeVRAyek0angs0fxptacIWOLKQhNByAysZJ2GHc4HW62gjKT",
    "ZgzhSNvE21YaTGBTp6ruWW5YyqE9hbArtKFoBb1F38BQA00z9TOy01cHc7RMUs6oqG7rmOoAUvQ",
    "OA+dphP9PrUHrVcKGMVWmATEdgz5ho4xdCqjEzjS+fcUENVIxytsJb7rZKup7xlHHHoYE910j1L",
    "ehgI5SyYTxDIigg3ZuC3rFoQVXdujJG8AD66LhgsEElN/6DppyDIoO4VT4yZytUXuaOeUilipiD",
    "UvggqrjEH1XQ+SXNzDodEDRHaGP03hhITNxV/cVG6Nv+Oa6rgv/nXKdTXLv1zthM972GLz9asHb",
    "CUWTcq79sH2ZnsAYeMbfoobugM35PcBas6gv0TtctvHMWFYwjIQC25QiYtW9clxCZYXtUyxSFeA",
    "scWEAEZp5Ifpiom1xZLWRSRNTTuvkpCLfKrYrDKgBDaFyjVGUaUCBM7/y5I2YdoGEaLSSybSsPE",
    "MegztBiR5Y0ZpINUIb+xazh7ZykeCHhmiIidlAluTa6N0XlNuKMid6iPGD7nGuMcv68SLWxc9O4",
    "JCGMUSucjIOPcyzOEHVJdau5B+jtmNmZi3QoWJp1UiymNCx6Dor9WcpnIuRkBPRUTIJis5rg18B",
    "YNagSjAxbGAJV7MOCl9NagUP+ll2921ynJ2p4fTK+cZHILAaOl1d10BDjKq2wBYZBboONmBfYRM",
    "jNNMGC/UsL/V53XP9+8fkYf++t6Z/f2mpfz8oxuHhZRMDR1F0526Ci9ukqbEK3HxvLs13s8J+YC",
    "7HJhxZwZEFbn59fQlfW8NLlq5lvhv1v79fL/HV8a9Wy3FHS7jnSzx7Jdx+YbN7nZ9+Y6/98cvv7",
    "39/79uffxht46+t8Ney3w73Xd1vv3WrGL8y75sWWXq8ksiq+MOLJX9wY935ZPhOvzcdmf5peFe0",
    "Uvmlmtxv5OuzRd56Sd75/duuV8MgznKCCrtRsW9zY2rz/YSb/90lefe32OPGkj8R8uuH18O/cFR",
    "ex70t+AP81S/57e78t4+uh8/5P98i/53Set/JevdL6jI0XD4qE6zG567+7osjjxn3tMj5v13+ef",
    "2q1Lv6jrhd+chjxl1XP986/rS/v6l+kNL7B0+wHpvyvU8/96Tp9SPx67deLcYfLL4nNGPGozU7m",
    "uIxbjoG657+R/z7T0/7zfvLtrNf8eH5i7vHgvIZbmHyLWJx+0y574eLRwqoXr9P/Dfqyfx6tKW/",
    "ulmKbzeeMBHJiX7jrcO3D69Tn/4ClDEgjg==",
    ""
  };

  static char newstr [1537] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_CameraCalImageCapture(SimStruct *S)
{
  const char* newstr = sf_c2_CameraCalImageCapture_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(4074653259U));
  ssSetChecksum1(S,(3824559465U));
  ssSetChecksum2(S,(1270300149U));
  ssSetChecksum3(S,(1808917158U));
}

static void mdlRTW_c2_CameraCalImageCapture(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_CameraCalImageCapture(SimStruct *S)
{
  SFc2_CameraCalImageCaptureInstanceStruct *chartInstance;
  chartInstance = (SFc2_CameraCalImageCaptureInstanceStruct *)utMalloc(sizeof
    (SFc2_CameraCalImageCaptureInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_CameraCalImageCaptureInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_CameraCalImageCapture;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CameraCalImageCapture;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c2_CameraCalImageCapture;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c2_CameraCalImageCapture;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_CameraCalImageCapture;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_CameraCalImageCapture;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_CameraCalImageCapture;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CameraCalImageCapture;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CameraCalImageCapture;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CameraCalImageCapture;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CameraCalImageCapture;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_CameraCalImageCapture;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c2_JITStateAnimation,
    chartInstance->c2_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_CameraCalImageCapture(chartInstance);
}

void c2_CameraCalImageCapture_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_CameraCalImageCapture(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CameraCalImageCapture(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CameraCalImageCapture(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CameraCalImageCapture_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
