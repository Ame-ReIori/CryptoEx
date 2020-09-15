#include "sha3.h"
#include "hmac_sha3.h"
#include <time.h>
#include <stdlib.h>

int main() {
	//uint8_t *s = "\\wkNAK]Uq__CiEeQBVHo>LIQ^P\\Jl^JMSut<T?xPSen=bxKv?erk=viOt^JWKSqqCg<gM]f[Wdm@fOZWZudxC_[T^wU`D\\ghYeuOOxI`wwiWPDhT@]CbQhGUKqwa[A]uEBc@P=Hjadt_xAr>UpVKtRBSYMNtcqr]Kpj<c`N?lreno_x`KKXfrtDApkR@gIRHQwawDtBhoRb<FZeSAWsS>gvktCksitVnP\\D=ZUh>=_wMTV\\AJjZ\\EROG=hxnPMDU^rnkhBMxn\\wTXcWoQTJEZJS<X\\eeF>hX<I[OsE?o>]=`g`>wjrPD[]bl_ueQvVup<QbHRJIpvuCnh]jY>TT`g@Mpq[i[ocRY\\GsovpVaBWwiGxsNcCKB=GVeLjsD<EIvemVnxBd^rog=FQoVMcudquNZ=J<`g_wG[]NjuH_BnpuiS[WVnWETP^anZElNZav`EwbD]pIlq\\o@EnSJTE<=MQmNcptNsEPHbF_jWpjmsGThbfjuOfKim<jJctHRxO@Rek^riQvnR[ZjBCkr^\\Kkbit@wqfiBw[s]VbRfLiiQst]JtEuOnm\\X@fZ_[ktnW>oJFvd\\OCcHnB<kf[F[PTd^[<JNngx[ptBGtALG_vcXoqpj]@=\\ED`wOCgHYwsfPfhOBBfNo]?WFv[BbNZjCFB\\JcuXL>cNiY_E\\>DmjiJWaXDX@vChedhNQTaJwTvwBl[HDCWJ_YGwinZGpHuAuYs^j=r<HibkhiBYwwNwiYMgB`\\e=@YUEnCc^P>OtNt]Yfe>^mM_Jo_oV_QoDe]siLJCpusZOogGiIBB=NeabWawqPI=beuSHXqbDcso@Vgrxw<d?tDwBV]I=?]hApxY<aBZPW=krVKHpYIVgafUL_QXmJ?]=A<_?>KbfXc\\<JUr>W>jtAQriJXiWHXxQGlYVmKJ<@XRSVrwrk>bPwBSvYAJXgNUScKrQ_nA?WLvlA?D?ME^vpMDSvKseJHW_C\\sn\\tfPhS_GVtP?etpH_][qQtD`]?JJSlL^\\@KoQ`mfdh`HLAYXcNJTE?ijgs]lnAoJK[Bh\\vce?dBIxwtdUAowiWTBSdAlieEwBD]d`qa@JtZ]Nq]apvCAECLgJhufYSH]ve=q`baP\\XF=tLaJ_ZU>MIoNSWckWwbAltwVXR`QL]NTOXN>jAAsLdi=`VENccVR]pFj\\oZPEgf?rhk>[G<eYIHqMaqrjCjc<wFZ=[Ql<hgNIvFrdQDgHs]TLiq<KTnFstCxIbxnnXeYWdk]UapIbS>apGHaa]hTHojqGiFW\\hSJcI`>clSFvjTo^^b[wIjVSUHQCDIL<LAWwxKOAWdqkTfwJtBqTT\\CwX[PtOkojQUrlqIBwvUQVt_d\\WMscRSBluHK[I\\>t]cCdIuxHxBm_lJ]=WMVolfdRqu]qKmlZvo=gSpOkPKbUVxwYgJ?lLNs`oQniDgo@TYeS[Qv<OSuKvK<r`kxB[VZkH?i]SkcitDfVp_@@q?IPKGZgZbWfneYBFXqXjZQ=hCr?DgEMrQF?oeY]kQm@Z\\t=CVL\\bP`MLlAUUTpZJIYeVoELmIGpgXUv=ora^\\nahaCQ<mACnCEAZXYOfItJF^pXlfYdbULZx>JVT>\\KifNr]b\\AstVNNbqe<Su]rcDg]IfLMjgWKudVD@BVuVeUXL<\\dt]^lLhhdRM^RHmvSsQRDdMiMoKpk>u`Aes=BuWDcmS@@<qaq<fWwYUcNb=ZIV^vL?GNNj]@d=@>kYl@LbYITvEB`qam_]qOftxY]eEJ`\\^Tx@Alip`EpbqaTwTODoL`lt>Ab?AHwfxQa]ubwJbT`Mcqv?PBpf<LuSCTg__a?xnGEeaFjEWDHdqTh[jr=T?HfPEhrQVRAhb?Xwj_`HtCL@>gpHaCSfFTwr_QHcswUYi]FfQCsm<AYTjAbD[pifkQ>]>L^ZnIQjbprZFRxgm@smf^TCx<eXn_sflUfTBSC<k^NRslIki`f?Ku]BnOQHFJlXLccS=PBKTLn=QJHdjhJWMY^uYRcjpLCG[dHMBZ<V>c??h]M<`LsM@Qjx`>UCFf<@ZPN`t^HfUD\\TQYDXqV`U>ck=ppgvHMfACUv@WuXrGm`UVXJ=ujNsMQVreE<vEMsxdK^iDqb=]=kk>bDbnH`rRiE_PwYPRfutoqduWTFrG^wTOQbbhCKG]DfHLZpgQs_jC=xwF]SDYtos@IasMTpedM>KZYZWKM^MAjaEF]MSPVLNIr\\@kWVAFZ\\lwc]ZWPIOoSORMLF=ljHjSqjHAl\\lJCnwLOFVaq\\pVaURiPM[DUxf<>jAY\\frFi]O]AiIf\\?LQafOuwGtGmVdo><Gg\\rH^v^`ptUtX]gkEgt^gVKI]GLwfoUvDdb[j@jYE`DpHTglqBdBC\\SjvAoWElSeoXjuMIS<VgZBAcYtNunrXCAJADMccqknETLrKPAqt?=AMTJdfvoZkNooGeHdjEjfSCOTijxRtX>`brJE`DpbBgICxVEr=Rlms`AOCBktlL[TI_ZUHj>qNAWFCuhis^fdtsPjIQbN[\\rjdFXMengV`af\\^b>b[@jvXWDseGYmh_Ng?tLcfhFPwisabZIZa^efGY@vG^t?XvkHgaw\\JtbRPnLJ]Wh=t^fxPmlEKHNUQQ@\\fLfVPW<fnbCi`cGKB[vfFlI`bCrC[tAVtBZj<N=wdckOpeDlmV@O`GEDjHLWtlIsBdec<_DdL>puh^=ouaTu\\?FLbEddcbJRptbr<NjTBYJQ]`K@tk[QtI^@kJKHqkljaUTdLsjtTEerfIrRErnasunkBAJ[HvfcfE=Aw^=PmmrGl?m_ocSCa_CVToUG`\\pX`Ih]IGevcCqqpd>Hq?ePeYWodEP\\QsKvIPe<wKxMKbYu>pJOamqtc`kMOjL[cIdvx[B\\dSoIK]<QtLTSIfEf_N`BKcGFhHpUOPNRlh@E<Qk\\@LUROAmbn]FfvKjXmEZDfvhH<<BWOsT_Z_LKZTKoBQSJ[SuEG?qXRD]QoAo\\SON>lmE[DtjBqG[\\@If]uFQMkwnkqMIEA[La<>p<XaQfUihH^K<?L^PIbrtLgBc>c[f\\MZqmnjaX_\\NTun@gguqZc`M?UqHXfVfLMUVfwjoqFDosDLdu\\WJCYTVTs<mshwKqJD]FSuH>LFJQmt`BuIm]rtW`u[wHEKSPR[b\\rjZuAmrDIb`iYPiixB]@dhkLS]LhioQK]Pg@wiA@IBAND_[NFqmTxOo\\bY]sYi>wqh<OrrEEbQhe^e`pp<mduwRUgJMBLgTCcJUtSplDRlZ]aLlhXwUiiiQ@\\Fbn[eNngEj=RaiJVmYW@pGpJvWRdWdx[PLtT\\AJ>hYbuE@VYgsV=kOQbaQl=Ri`[pV_gOskhZkGIwbJYjIuDNsY>\\PHeJEoFjZ\\>XQRew<N\\I]CN]_CPK@HVG\\?konEM]TUbulSAPYCYYD<KTSTMJIRaScmYHlnBI`hVYpnRAPbLEcg]NFOvp]jAvLxUmaKlprM`cxflHfxfMbrP`KgHb_e_l?rYpikHgM=CgtD?j\\diQ[J`rxKlB]jK?GkDtwSgnUuD>UMnvFLxAcrBj_T=TwZwfOtw>qBSW<[OovLBwZ^c@Zt?OPwwt=xJigPHQuupDi>gXQcIu_fwbet=du_haU]dvFjuGDQGoYa`MMIJx=IljgVjgihMjmkrPMkZ]o>GJUbh^YcATQWdjqvFjVPCo\\t=P]Rb[RurFrO=kkvRnhR_aZJo_LEmUvprrDirx?pd?UWiscXJX\\aY_HJJZFv?mPNisBo<g>uJKvF^_H>DoeNgZKUoW=tYHggsbvjg<Xnmj>KpItEppHNZDHd\\_prA`MN[fAZ^Ba?fvAnugBmhiOZd@_Eprw[v<eoYppgwD^vwm]gr]jxCHcbWSMIf?pPOc]RmIsGsScOegtpDXdJSmQAZObMMSU?NhgBPCi`gdVfY]Vf@hIQWTPBRj]LbddGFjO@bJ^lWlk]nB\\wj<Xj^bvijSuqvOlpkTdwNd>XXF_aHo^`rO^^UBVwCUDXN^a]i^axYrKGxgw]eEFtDZMYKt_OSAcmiNvgOSA<AdB>mJWE>l=FWfd`>fgCeDVKDD>n\\PRcFHwxKsAxG=CXLDjmRN[mwOWaKkbbDkwY`nuBP>>KlBELEZUkcN`Ai]K_gdE_WbMQHopaKOko<?o@cCWebNom@CExPItMFGcv^CYHjwLSFkerwfbUP]dYYbnxBW<Fsdhj?i?XawQOIjwRkdg^TogZcforec>u\\L<D\\lPBsjGuL>aqqm[>ZJKcawd?pTqlnjYM=`bExhF`_@Osbh[WMpTUQ_fEtjREBHWHKNTVYhimvPi`\\dD[=nZoMXca\\YX==QJs`o\\@[TdtpJMBc[HOdeJK_^knwtGiIZJe>tVXkTgaBwoeIMkQT=D\\\\N``FX<=pojJSUjxct@oLYE\\PBS_tDDMdAm=rBHMGg<wgv[W`WFVl[SXPM?[K^XQRvC`mL=OGterZ\\lIW^lMQ^GgQfKk?VN^Qpb[KSVA>oZG>>XVLmqDAmKnbYgOvlwJQnhPY<<tui=FF?QhPsCXWtteBJ[kMfiBAu`Ltk?DJ]AQ[dAPaTculFPU=g``jA`VAdBKOcaiQ]koCwNElqgBJkBZMGkVISH<GTv\\hBqJC__IXVHSb>=f=tXihUIrkKWG^xp>dpp<hUxVSNFeBalWHsiw`JABllpDnsHkFvuskFxBFx]SqGagYood`P]\\FS]LT`eoFgSanIk@>KkwjOkkoLjvqClE=NlUvb>p_v<ASoFOIuJ_>tQ@km][DooUo=Yt^[dFAo^T^\\GDqE?o_uo`WYWMnVx_OjqHuG\\PpUoN[T<BQmtZOZq\\@kLOVIYYlX[cDSLq^lNT<ISFdOhXY\\HXnC^nwhiHVIYB\\\\jxM[QX^`N]pc[IBGcnTXeWXm`I_>L?uZdJd\\s?\\@pYdlEnRAGpRqpVeDpgvL^r\\VOCltQgnHCjrvfs@OsuP<T\\t?QHCElJWGDfHgtPRSwbOtm[^WNurLaVbWq=EVk>xsUBgROnq<R]KwZpfjbWSsSHkcS>Z<OXA^g";
	uint8_t *s = "abcd";
	uint8_t *key = "aaaa";
	SHA3_OUT out;
	
	
	printf("SHA3_224 result: ");
	SHA3_224(&out, s, strlen(s));
	SHA3_PRINT(&out);
	printf("SHA3_256 result: ");
	SHA3_256(&out, s, strlen(s));
	SHA3_PRINT(&out);
	printf("SHA3_384 result: ");
	SHA3_384(&out, s, strlen(s));
	SHA3_PRINT(&out);
	printf("SHA3_512 result: ");
	SHA3_512(&out, s, strlen(s));
	SHA3_PRINT(&out);
	
	//printf("time=%fs\n", (double)(end - start) / CLK_TCK);

	printf("HMAC_SHA3_224 result: ");
	HMAC_SHA3_224(key, strlen(key), s, strlen(s), &out);
	SHA3_PRINT(&out);
	printf("HMAC_SHA3_256 result: ");
	HMAC_SHA3_256(key, strlen(key), s, strlen(s), &out);
	SHA3_PRINT(&out);
	printf("HMAC_SHA3_384 result: ");
	HMAC_SHA3_384(key, strlen(key), s, strlen(s), &out);
	SHA3_PRINT(&out);
	printf("HMAC_SHA3_512 result: ");
	HMAC_SHA3_512(key, strlen(key), s, strlen(s), &out);
	SHA3_PRINT(&out);

	system("pause");
	
}
