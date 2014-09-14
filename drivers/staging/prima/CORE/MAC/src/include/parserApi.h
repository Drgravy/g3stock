/*
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
                                                        
                                                      
                                     
                                  
                          
            
                                                         
                                                                       
  
 */
#ifndef __PARSE_H__
#define __PARSE_H__

#include <stdarg.h>
#include "sirMacPropExts.h"
#include "dot11f.h"
#include "limSession.h"

#define COUNTRY_STRING_LENGTH    (  3 )
#define COUNTRY_INFO_MAX_CHANNEL ( 84 )
#define MAX_SIZE_OF_TRIPLETS_IN_COUNTRY_IE (COUNTRY_STRING_LENGTH * COUNTRY_INFO_MAX_CHANNEL)
#define HIGHEST_24GHZ_CHANNEL_NUM  ( 14 )

#define IS_24G_CH(__chNum) ((__chNum > 0) && (__chNum < 14))
#define IS_5G_CH(__chNum) ((__chNum >= 36) && (__chNum <= 165))

typedef struct sSirCountryInformation
{
    tANI_U8 countryString[COUNTRY_STRING_LENGTH];
    tANI_U8 numIntervals; //                           
    struct channelPowerLim
    {
        tANI_U8 channelNumber;
        tANI_U8 numChannel;
        tANI_U8 maxTransmitPower;
    } channelTransmitPower[COUNTRY_INFO_MAX_CHANNEL];
} tSirCountryInformation,*tpSirCountryInformation;


//                                              
typedef struct sSirProbeRespBeacon
{
    tSirMacTimeStamp          timeStamp;
    tANI_U16                  beaconInterval;
    tSirMacCapabilityInfo     capabilityInfo;

    tSirMacSSid               ssId;
    tSirMacRateSet            supportedRates;
    tSirMacRateSet            extendedRates;
    tSirMacChanNum            channelNumber;
    tSirMacCfParamSet         cfParamSet;
    tSirMacTim                tim;
    tSirMacEdcaParamSetIE     edcaParams;
    tSirMacQosCapabilityIE    qosCapability;

    tSirCountryInformation    countryInfoParam;
    tSirMacWpaInfo            wpa;
    tSirMacRsnInfo            rsn;

    tSirMacErpInfo            erpIEInfo;

    tSirPropIEStruct          propIEinfo;
    tDot11fIEPowerConstraints localPowerConstraint;
    tDot11fIETPCReport        tpcReport;
    tDot11fIEChanSwitchAnn    channelSwitchIE;
    tDot11fIEExtChanSwitchAnn extChannelSwitchIE;
    tSirMacAddr               bssid;
    tDot11fIEQuiet            quietIE;
    tDot11fIEHTCaps           HTCaps;
    tDot11fIEHTInfo           HTInfo;
    tDot11fIEP2PProbeRes      P2PProbeRes;
#ifdef WLAN_FEATURE_VOWIFI_11R
    tANI_U8                   mdie[SIR_MDIE_SIZE];
#endif
#ifdef FEATURE_WLAN_CCX
    tDot11fIECCXTxmitPower    ccxTxPwr;
    tDot11fIEQBSSLoad         QBSSLoad;
#endif
    tANI_U8                   ssidPresent;
    tANI_U8                   suppRatesPresent;
    tANI_U8                   extendedRatesPresent;
    tANI_U8                   cfPresent;
    tANI_U8                   dsParamsPresent;
    tANI_U8                   timPresent;

    tANI_U8                   edcaPresent;
    tANI_U8                   qosCapabilityPresent;
    tANI_U8                   wmeEdcaPresent;
    tANI_U8                   wmeInfoPresent;
    tANI_U8                   wsmCapablePresent;

    tANI_U8                   countryInfoPresent;
    tANI_U8                   wpaPresent;
    tANI_U8                   rsnPresent;
    tANI_U8                   erpPresent;
    tANI_U8                   channelSwitchPresent;
    tANI_U8                   extChannelSwitchPresent;
    tANI_U8                   quietIEPresent;
    tANI_U8                   tpcReportPresent;
    tANI_U8                   powerConstraintPresent;

#ifdef WLAN_FEATURE_VOWIFI_11R
    tANI_U8                   mdiePresent;
#endif

#ifdef WLAN_FEATURE_11AC
    tDot11fIEVHTCaps          VHTCaps;
    tDot11fIEVHTOperation     VHTOperation;
    tDot11fIEVHTExtBssLoad    VHTExtBssLoad;
    tDot11fIEOperatingMode    OperatingMode;
    tANI_U8                   WiderBWChanSwitchAnnPresent;
    tDot11fIEWiderBWChanSwitchAnn WiderBWChanSwitchAnn;
#endif

} tSirProbeRespBeacon, *tpSirProbeRespBeacon;

//                        
typedef struct sSirProbeReq
{
    tSirMacSSid               ssId;
    tSirMacRateSet            supportedRates;
    tSirMacRateSet            extendedRates;
    tDot11fIEWscProbeReq      probeReqWscIeInfo;
    tDot11fIEHTCaps           HTCaps;
    tANI_U8                   ssidPresent;
    tANI_U8                   suppRatesPresent;
    tANI_U8                   extendedRatesPresent;
    tANI_U8                   wscIePresent;
    tANI_U8                   p2pIePresent;
#ifdef WLAN_FEATURE_11AC
    tDot11fIEVHTCaps          VHTCaps;
#endif


} tSirProbeReq, *tpSirProbeReq;

//                                                          
//                      
typedef struct sSirAssocReq
{

    tSirMacCapabilityInfo     capabilityInfo;
    tANI_U16                  listenInterval;
    tSirMacAddr               currentApAddr; /*                        */
    tSirMacSSid               ssId;
    tSirMacRateSet            supportedRates;
    tSirMacRateSet            extendedRates;

    tSirAddtsReqInfo          addtsReq;
    tSirMacQosCapabilityStaIE qosCapability;

    tSirMacWpaInfo            wpa;
    tSirMacRsnInfo            rsn;
    tSirAddie                 addIE;
    
    tSirPropIEStruct          propIEinfo;
    tSirMacPowerCapabilityIE  powerCapability;
    tSirMacSupportedChannelIE supportedChannels;
    tDot11fIEHTCaps   HTCaps;
    tDot11fIEWMMInfoStation   WMMInfoStation;
    //                                                
    tANI_U8                   reassocRequest;
    tANI_U8                   ssidPresent;
    tANI_U8                   suppRatesPresent;
    tANI_U8                   extendedRatesPresent;

    tANI_U8                   wmeInfoPresent;
    tANI_U8                   qosCapabilityPresent;
    tANI_U8                   addtsPresent;
    tANI_U8                   wsmCapablePresent;

    tANI_U8                   wpaPresent;
    tANI_U8                   rsnPresent;
    tANI_U8                   addIEPresent;

    tANI_U8                   powerCapabilityPresent;
    tANI_U8                   supportedChannelsPresent;
    //                                                    
    //                                                  
    tANI_U32                  assocReqFrameLength;
    tANI_U8*                  assocReqFrame;
#ifdef WLAN_FEATURE_11AC
    tDot11fIEVHTCaps          VHTCaps;
    tDot11fIEOperatingMode    operMode;
#endif
} tSirAssocReq, *tpSirAssocReq;


//                                                           
//                      
typedef struct sSirAssocRsp
{

    tSirMacCapabilityInfo     capabilityInfo;
    tANI_U16                  aid;
    tANI_U16                  statusCode;
    tSirMacRateSet            supportedRates;
    tSirMacRateSet            extendedRates;
    tSirPropIEStruct          propIEinfo;
    tSirMacEdcaParamSetIE     edca;
    tSirAddtsRspInfo          addtsRsp;
    tDot11fIEHTCaps   HTCaps;
    tDot11fIEHTInfo           HTInfo;
#if defined WLAN_FEATURE_VOWIFI_11R
    tDot11fIEFTInfo           FTInfo;
    tANI_U8                   mdie[SIR_MDIE_SIZE];
    tANI_U8                   num_RICData; 
    tDot11fIERICDataDesc      RICData[2];
#endif

#ifdef FEATURE_WLAN_CCX
    tANI_U8                   num_tspecs;
    tDot11fIEWMMTSPEC         TSPECInfo[SIR_CCX_MAX_TSPEC_IES];
    tSirMacCCXTSMIE           tsmIE;
#endif

    tANI_U8                   suppRatesPresent;
    tANI_U8                   extendedRatesPresent;

    tANI_U8                   edcaPresent;
    tANI_U8                   wmeEdcaPresent;
    tANI_U8                   addtsPresent;
    tANI_U8                   wsmCapablePresent;
#if defined WLAN_FEATURE_VOWIFI_11R
    tANI_U8                   ftinfoPresent;
    tANI_U8                   mdiePresent;
    tANI_U8                   ricPresent;
#endif
#ifdef FEATURE_WLAN_CCX
    tANI_U8                   tspecPresent;
    tANI_U8                   tsmPresent;
#endif    
#ifdef WLAN_FEATURE_11AC
    tDot11fIEVHTCaps          VHTCaps;
    tDot11fIEVHTOperation     VHTOperation;
#endif
} tSirAssocRsp, *tpSirAssocRsp;

#if defined(FEATURE_WLAN_CCX_UPLOAD)
//                                                  
typedef struct sSirCcxBcnReportMandatoryIe
{
    tSirMacSSid           ssId;
    tSirMacRateSet        supportedRates;
    tSirMacFHParamSet     fhParamSet;
    tSirMacDsParamSetIE   dsParamSet;
    tSirMacCfParamSet     cfParamSet;
    tSirMacIBSSParams     ibssParamSet;
    tSirMacTim            tim;
    tSirMacRRMEnabledCap  rmEnabledCapabilities;

    tANI_U8               ssidPresent;
    tANI_U8               suppRatesPresent;
    tANI_U8               fhParamPresent;
    tANI_U8               dsParamsPresent;
    tANI_U8               cfPresent;
    tANI_U8               ibssParamPresent;
    tANI_U8               timPresent;
    tANI_U8               rrmPresent;
} tSirCcxBcnReportMandatoryIe, *tpSirCcxBcnReportMandatoryIe;
#endif /*                         */

tANI_U8
sirIsPropCapabilityEnabled(struct sAniSirGlobal *pMac, tANI_U32 bitnum);

tSirRetStatus
sirGetCfgPropCaps(struct sAniSirGlobal *, tANI_U16 *);

void dot11fLog(tpAniSirGlobal pMac, int nSev, const char *lpszFormat, ...);

#define CFG_GET_INT(nStatus, pMac, nItem, cfg )  do {                \
        (nStatus) = wlan_cfgGetInt( (pMac), (nItem), & (cfg) );      \
        if ( eSIR_SUCCESS != (nStatus) )                             \
        {                                                            \
            dot11fLog( (pMac), LOGP, FL("Failed to retrieve "        \
                                        #nItem " from CFG (%d)."), \
                       (nStatus) );                                  \
            return nStatus;                                          \
        }                                                            \
    } while (0)

#define CFG_GET_INT_NO_STATUS(nStatus, pMac, nItem, cfg ) do {       \
        (nStatus) = wlan_cfgGetInt( (pMac), (nItem), & (cfg) );      \
        if ( eSIR_SUCCESS != (nStatus) )                             \
        {                                                            \
            dot11fLog( (pMac), LOGP, FL("Failed to retrieve "        \
                                        #nItem " from CFG (%d)."), \
                       (nStatus) );                                  \
            return;                                                  \
        }                                                            \
    } while (0)

#define CFG_GET_STR(nStatus, pMac, nItem, cfg, nCfg, nMaxCfg) do {      \
        (nCfg) = (nMaxCfg);                                             \
        (nStatus) = wlan_cfgGetStr( (pMac), (nItem), (cfg), & (nCfg) ); \
        if ( eSIR_SUCCESS != (nStatus) )                                \
        {                                                               \
            dot11fLog( (pMac), LOGP, FL("Failed to retrieve "           \
                                        #nItem " from CFG (%d)."),    \
                       (nStatus) );                                     \
            return nStatus;                                             \
        }                                                               \
    } while (0)

#define CFG_GET_STR_NO_STATUS(nStatus, pMac, nItem, cfg, nCfg,          \
                              nMaxCfg) do {                             \
        (nCfg) = (nMaxCfg);                                             \
        (nStatus) = wlan_cfgGetStr( (pMac), (nItem), (cfg), & (nCfg) ); \
        if ( eSIR_SUCCESS != (nStatus) )                                \
        {                                                               \
            dot11fLog( (pMac), LOGP, FL("Failed to retrieve "           \
                                        #nItem " from CFG (%d)."),    \
                       (nStatus) );                                     \
            return;                                                     \
        }                                                               \
    } while (0)

void swapBitField16(tANI_U16 in, tANI_U16 *out);

//                                                                    
//                

tSirRetStatus
sirConvertProbeReqFrame2Struct(struct sAniSirGlobal *pMac,
                               tANI_U8 *frame,
                               tANI_U32 len,
                               tpSirProbeReq probe);

tSirRetStatus
sirConvertProbeFrame2Struct(struct sAniSirGlobal *pMac, tANI_U8 *frame,
                            tANI_U32 len,
                            tpSirProbeRespBeacon probe);

tSirRetStatus
sirConvertAssocReqFrame2Struct(struct sAniSirGlobal *pMac,
                               tANI_U8 * frame,
                               tANI_U32 len,
                               tpSirAssocReq assoc);

tSirRetStatus
sirConvertAssocRespFrame2Struct(struct sAniSirGlobal *pMac,
                                tANI_U8 * frame,
                                tANI_U32 len,
                                tpSirAssocRsp assoc);

tSirRetStatus
sirConvertReassocReqFrame2Struct(struct sAniSirGlobal *pMac,
                                 tANI_U8 * frame,
                                 tANI_U32 len,
                                 tpSirAssocReq assoc);

tSirRetStatus
sirParseBeaconIE(struct sAniSirGlobal *pMac,
                 tpSirProbeRespBeacon   pBeaconStruct,
                 tANI_U8                    *pPayload,
                 tANI_U32                    payloadLength);

#if defined(FEATURE_WLAN_CCX_UPLOAD)
tSirRetStatus
sirFillBeaconMandatoryIEforCcxBcnReport(tpAniSirGlobal    pMac,
                                        tANI_U8          *pPayload,
                                        const tANI_U32    payloadLength,
                                        tANI_U8         **outIeBuf,
                                        tANI_U32         *pOutIeLen);
#endif /*                         */

tSirRetStatus
sirConvertBeaconFrame2Struct(struct sAniSirGlobal *pMac,
                             tANI_U8 *pBeaconFrame,
                             tpSirProbeRespBeacon pBeaconStruct);

tSirRetStatus
sirConvertAuthFrame2Struct(struct sAniSirGlobal *pMac,
                           tANI_U8 * frame,
                           tANI_U32 len,
                           tpSirMacAuthFrameBody auth);

tSirRetStatus
sirConvertAddtsReq2Struct(struct sAniSirGlobal *pMac,
                          tANI_U8 *frame,
                          tANI_U32 len,
                          tSirAddtsReqInfo *addTs);

tSirRetStatus
sirConvertAddtsRsp2Struct(struct sAniSirGlobal *pMac,
                          tANI_U8 *frame,
                          tANI_U32 len,
                          tSirAddtsRspInfo *addts);

tSirRetStatus
sirConvertDeltsReq2Struct(struct sAniSirGlobal *pMac,
                          tANI_U8 *frame,
                          tANI_U32 len,
                          tSirDeltsReqInfo *delTs);

#ifdef ANI_SUPPORT_11H
tSirRetStatus
sirConvertTpcReqFrame2Struct(struct sAniSirGlobal *, tANI_U8 *,
                             tpSirMacTpcReqActionFrame, tANI_U32);

tSirRetStatus
sirConvertMeasReqFrame2Struct(struct sAniSirGlobal *, tANI_U8 *,
                              tpSirMacMeasReqActionFrame, tANI_U32);
#endif


/* 
                                           
  
                                   
  
  
                                                      
  
                                                                    
  
  
                                                                          
                 
  
  
 */

tSirRetStatus
PopulateDot11fCapabilities(tpAniSirGlobal         pMac,
                           tDot11fFfCapabilities *pDot11f,
                           tpPESession            psessionEntry);

/* 
                                           
  
                                   
  
  
                                                      
  
                                                                    
  
                                                            
  
  
                                                                        
                               
  
  
 */

struct sDphHashNode;

tSirRetStatus
PopulateDot11fCapabilities2(tpAniSirGlobal         pMac,
                            tDot11fFfCapabilities *pDot11f,
                            struct sDphHashNode   *pSta,
                            tpPESession            psessionEntry);

//                                   
void
PopulateDot11fChanSwitchAnn(tpAniSirGlobal          pMac,
                            tDot11fIEChanSwitchAnn *pDot11f,
                            tpPESession psessionEntry);

//                                   
void
PopulateDot11fExtChanSwitchAnn(tpAniSirGlobal          pMac,
                             tDot11fIEExtChanSwitchAnn *pDot11f,
                             tpPESession psessionEntry);

//                             
tSirRetStatus
PopulateDot11fCountry(tpAniSirGlobal    pMac,
                      tDot11fIECountry *pDot11f,  tpPESession psessionEntry);

//                                    
tSirRetStatus
PopulateDot11fDSParams(tpAniSirGlobal     pMac,
                       tDot11fIEDSParams *pDot11f, tANI_U8 channel,
                       tpPESession psessionEntry);


//                                   
void
PopulateDot11fEDCAParamSet(tpAniSirGlobal         pMac,
                           tDot11fIEEDCAParamSet *pDot11f,
                           tpPESession psessionEntry);

tSirRetStatus
PopulateDot11fERPInfo(tpAniSirGlobal    pMac,
                      tDot11fIEERPInfo *pDot11f, tpPESession psessionEntry);

tSirRetStatus
PopulateDot11fExtSuppRates(tpAniSirGlobal      pMac,
                           tANI_U8  nChannelNum, tDot11fIEExtSuppRates *pDot11f,
                           tpPESession psessionEntry);

#if defined WLAN_FEATURE_VOWIFI
tSirRetStatus 
PopulateDot11fBeaconReport(tpAniSirGlobal       pMac, 
                           tDot11fIEMeasurementReport *pDot11f, 
                           tSirMacBeaconReport *pBeaconReport );
#endif

/* 
                                          
  
  
                                                      
  
                                                                            
  
                                                                            
  
  
                                                          
  
  
 */

tSirRetStatus
PopulateDot11fExtSuppRates1(tpAniSirGlobal         pMac,
                            tANI_U8                     nChannelNum,
                            tDot11fIEExtSuppRates *pDot11f);

tSirRetStatus
PopulateDot11fHCF(tpAniSirGlobal  pMac,
                  tANI_U32        capEnable,
                  tDot11fIEHCF   *pDot11f);

tSirRetStatus
PopulateDot11fHTCaps(tpAniSirGlobal           pMac,
                           tpPESession      psessionEntry,
                           tDot11fIEHTCaps *pDot11f);

tSirRetStatus
PopulateDot11fHTInfo(tpAniSirGlobal   pMac,
                     tDot11fIEHTInfo *pDot11f,
                     tpPESession      psessionEntry);

void PopulateDot11fIBSSParams(tpAniSirGlobal  pMac,
       tDot11fIEIBSSParams *pDot11f, tpPESession psessionEntry);

#ifdef ANI_SUPPORT_11H
tSirRetStatus
PopulateDot11fMeasurementReport0(tpAniSirGlobal              pMac,
                                 tpSirMacMeasReqActionFrame  pReq,
                                 tDot11fIEMeasurementReport *pDot11f);

//                                                                   
tSirRetStatus
PopulateDot11fMeasurementReport1(tpAniSirGlobal              pMac,
                                 tpSirMacMeasReqActionFrame  pReq,
                                 tDot11fIEMeasurementReport *pDot11f);

//                                                                        
tSirRetStatus
PopulateDot11fMeasurementReport2(tpAniSirGlobal              pMac,
                                 tpSirMacMeasReqActionFrame  pReq,
                                 tDot11fIEMeasurementReport *pDot11f);
#endif  //               

//                               
void
PopulateDot11fPowerCaps(tpAniSirGlobal  pMac,
                        tDot11fIEPowerCaps *pCaps,
                        tANI_U8 nAssocType,tpPESession psessionEntry);

//                                      
tSirRetStatus
PopulateDot11fPowerConstraints(tpAniSirGlobal             pMac,
                               tDot11fIEPowerConstraints *pDot11f);

tSirRetStatus
PopulateDot11fPropCapability(tpAniSirGlobal           pMac,
                             tANI_U32                      capEnable,
                             tDot11fIEPropCapability *pDot11f);

void
PopulateDot11fPropChannSwitchAnn(tpAniSirGlobal               pMac,
                                 tANI_U32                          capEnable,
                                 tDot11fIEPropChannSwitchAnn *pDot11f);

void
PopulateDot11fPropEDCAParams(tpAniSirGlobal           pMac,
                             tANI_U16                      caps,
                             tDot11fIEPropEDCAParams *pDot11f);

tSirRetStatus
PopulateDot11fPropSuppRates(tpAniSirGlobal          pMac,
                            tANI_U32                     capEnable,
                            tDot11fIEPropSuppRates *pDot11f);

void
PopulateDot11fQOSCapsAp(tpAniSirGlobal      pMac,
                        tDot11fIEQOSCapsAp *pDot11f, tpPESession psessionEntry);

void
PopulateDot11fQOSCapsStation(tpAniSirGlobal           pMac,
                             tDot11fIEQOSCapsStation *pDot11f);

tSirRetStatus 
PopulateDot11fRSN(tpAniSirGlobal  pMac,
                  tpSirRSNie      pRsnIe,
                  tDot11fIERSN   *pDot11f);

tSirRetStatus
PopulateDot11fRSNOpaque( tpAniSirGlobal      pMac,
                  tpSirRSNie      pRsnIe,
                         tDot11fIERSNOpaque *pDot11f );

#if defined(FEATURE_WLAN_WAPI)

tSirRetStatus
PopulateDot11fWAPI(tpAniSirGlobal  pMac,
                  tpSirRSNie      pRsnIe,
                  tDot11fIEWAPI   *pDot11f);

tSirRetStatus PopulateDot11fWAPIOpaque( tpAniSirGlobal      pMac,
                                       tpSirRSNie          pRsnIe,
                                       tDot11fIEWAPIOpaque *pDot11f );

#endif //                          

//                                              
void
PopulateDot11fSSID(tpAniSirGlobal pMac,
                   tSirMacSSid   *pInternal,
                   tDot11fIESSID *pDot11f);

//                                   
tSirRetStatus
PopulateDot11fSSID2(tpAniSirGlobal pMac,
                    tDot11fIESSID *pDot11f);


/* 
                                      
  
                                
  
  
                                                         
  
                                                                
  
  
 */

void
PopulateDot11fSchedule(tSirMacScheduleIE *pSchedule,
                       tDot11fIESchedule *pDot11f);

void
PopulateDot11fSuppChannels(tpAniSirGlobal         pMac,
                           tDot11fIESuppChannels *pDot11f,
                           tANI_U8 nAssocType,tpPESession psessionEntry);

/* 
                                        
  
  
                                                      
  
                                                                           
        
  
                                                                         
  
  
                                                                 
                                                                       
                                                                          
                                                                          
                                                       
  
  
 */

#define POPULATE_DOT11F_RATES_OPERATIONAL ( 0xff )

tSirRetStatus
PopulateDot11fSuppRates(tpAniSirGlobal      pMac,
                        tANI_U8                  nChannelNum,
                        tDot11fIESuppRates *pDot11f,tpPESession);


tSirRetStatus PopulateDot11fTPCReport(tpAniSirGlobal      pMac,
                                      tDot11fIETPCReport *pDot11f,
                                      tpPESession psessionEntry);

//                           
void PopulateDot11fTSInfo(tSirMacTSInfo   *pInfo,
                          tDot11fFfTSInfo *pDot11f);


void PopulateDot11fWMM(tpAniSirGlobal      pMac,
                       tDot11fIEWMMInfoAp  *pInfo,
                       tDot11fIEWMMParams *pParams,
                       tDot11fIEWMMCaps   *pCaps,
                       tpPESession        psessionEntry);

void PopulateDot11fWMMCaps(tDot11fIEWMMCaps *pCaps);

#if defined(FEATURE_WLAN_CCX)
//                        
void PopulateDot11fCCXVersion(tDot11fIECCXVersion *pCCXVersion);
//                                     
void PopulateDot11fCCXRadMgmtCap(tDot11fIECCXRadMgmtCap *pCCXRadMgmtCap);
//                 
tSirRetStatus PopulateDot11fCCXCckmOpaque( tpAniSirGlobal pMac,
                                           tpSirCCKMie    pCCKMie,
                                           tDot11fIECCXCckmOpaque *pDot11f );

void PopulateDot11TSRSIE(tpAniSirGlobal  pMac,
                               tSirMacCCXTSRSIE     *pOld,
                               tDot11fIECCXTrafStrmRateSet  *pDot11f,
                               tANI_U8 rate_length);
void PopulateDot11fReAssocTspec(tpAniSirGlobal pMac, tDot11fReAssocRequest *pReassoc, tpPESession psessionEntry);
#endif

void PopulateDot11fWMMInfoAp(tpAniSirGlobal      pMac,
                             tDot11fIEWMMInfoAp *pInfo,
                             tpPESession psessionEntry);

void PopulateDot11fWMMInfoStation(tpAniSirGlobal           pMac,
                                  tDot11fIEWMMInfoStation *pInfo);

void PopulateDot11fWMMParams(tpAniSirGlobal      pMac,
                             tDot11fIEWMMParams *pParams,
                             tpPESession        psessionEntry);

/* 
                                         
  
                              
  
  
                                                         
  
                                                                   
  
  
 */

void
PopulateDot11fWMMSchedule(tSirMacScheduleIE    *pSchedule,
                          tDot11fIEWMMSchedule *pDot11f);

tSirRetStatus
PopulateDot11fWPA(tpAniSirGlobal  pMac,
                  tpSirRSNie      pRsnIe,
                  tDot11fIEWPA   *pDot11f);

tSirRetStatus
PopulateDot11fWPAOpaque( tpAniSirGlobal      pMac,
                         tpSirRSNie          pRsnIe,
                         tDot11fIEWPAOpaque *pDot11f );

void
PopulateDot11fTSPEC(tSirMacTspecIE  *pOld,
                    tDot11fIETSPEC  *pDot11f);

void
PopulateDot11fWMMTSPEC(tSirMacTspecIE     *pOld,
                       tDot11fIEWMMTSPEC  *pDot11f);

tSirRetStatus
PopulateDot11fTCLAS(tpAniSirGlobal  pMac,
                    tSirTclasInfo  *pOld,
                    tDot11fIETCLAS *pDot11f);

tSirRetStatus
PopulateDot11fWMMTCLAS(tpAniSirGlobal     pMac,
                       tSirTclasInfo     *pOld,
                       tDot11fIEWMMTCLAS *pDot11f);


tSirRetStatus PopulateDot11fWsc(tpAniSirGlobal pMac,
                                tDot11fIEWscBeacon *pDot11f);

tSirRetStatus PopulateDot11fWscRegistrarInfo(tpAniSirGlobal pMac,
                                             tDot11fIEWscBeacon *pDot11f);

tSirRetStatus DePopulateDot11fWscRegistrarInfo(tpAniSirGlobal pMac,
                                               tDot11fIEWscBeacon *pDot11f);

tSirRetStatus PopulateDot11fProbeResWPSIEs(tpAniSirGlobal pMac, tDot11fIEWscProbeRes *pDot11f, tpPESession psessionEntry);
tSirRetStatus PopulateDot11fAssocResWPSIEs(tpAniSirGlobal pMac, tDot11fIEWscAssocRes *pDot11f, tpPESession psessionEntry);
tSirRetStatus PopulateDot11fBeaconWPSIEs(tpAniSirGlobal pMac, tDot11fIEWscBeacon *pDot11f, tpPESession psessionEntry);

tSirRetStatus PopulateDot11fWscInProbeRes(tpAniSirGlobal pMac,
                                          tDot11fIEWscProbeRes *pDot11f);

tSirRetStatus PopulateDot11fWscRegistrarInfoInProbeRes(tpAniSirGlobal pMac,
                                                       tDot11fIEWscProbeRes *pDot11f);

tSirRetStatus DePopulateDot11fWscRegistrarInfoInProbeRes(tpAniSirGlobal pMac,
                                                         tDot11fIEWscProbeRes *pDot11f);


tSirRetStatus PopulateDot11fAssocResWscIE(tpAniSirGlobal pMac, 
                                          tDot11fIEWscAssocRes *pDot11f, 
                                          tpSirAssocReq pRcvdAssocReq);

tSirRetStatus PopulateDot11AssocResP2PIE(tpAniSirGlobal pMac, 
                                       tDot11fIEP2PAssocRes *pDot11f, 
                                       tpSirAssocReq pRcvdAssocReq);

tSirRetStatus PopulateDot11fWscInAssocRes(tpAniSirGlobal pMac,
                                          tDot11fIEWscAssocRes *pDot11f);


#if defined WLAN_FEATURE_VOWIFI
tSirRetStatus PopulateDot11fWFATPC( tpAniSirGlobal        pMac,
                                    tDot11fIEWFATPC *pDot11f, tANI_U8 txPower, tANI_U8 linkMargin );

tSirRetStatus PopulateDot11fRRMIe( tpAniSirGlobal pMac, 
                                   tDot11fIERRMEnabledCap *pDot11f, 
                                   tpPESession    psessionEntry );
#endif

#if defined WLAN_FEATURE_VOWIFI_11R
void PopulateMDIE( tpAniSirGlobal        pMac,
                   tDot11fIEMobilityDomain *pDot11f, tANI_U8 mdie[] );
void PopulateFTInfo( tpAniSirGlobal      pMac,
                     tDot11fIEFTInfo     *pDot11f );
#endif

void PopulateDot11fAssocRspRates ( tpAniSirGlobal pMac, tDot11fIESuppRates *pSupp, 
      tDot11fIEExtSuppRates *pExt, tANI_U16 *_11bRates, tANI_U16 *_11aRates );

int FindIELocation( tpAniSirGlobal pMac,
                           tpSirRSNie pRsnIe,
                           tANI_U8 EID);
#endif

#ifdef WLAN_FEATURE_11AC
tSirRetStatus
PopulateDot11fVHTCaps(tpAniSirGlobal  pMac, tDot11fIEVHTCaps *pDot11f);

tSirRetStatus
PopulateDot11fVHTOperation(tpAniSirGlobal  pMac, tDot11fIEVHTOperation  *pDot11f);

tSirRetStatus
PopulateDot11fVHTExtBssLoad(tpAniSirGlobal  pMac, tDot11fIEVHTExtBssLoad   *pDot11f);

tSirRetStatus
PopulateDot11fExtCap(tpAniSirGlobal pMac, tDot11fIEExtCap * pDot11f);

tSirRetStatus
PopulateDot11fOperatingMode(tpAniSirGlobal pMac, tDot11fIEOperatingMode *pDot11f, tpPESession psessionEntry );

void
PopulateDot11fWiderBWChanSwitchAnn(tpAniSirGlobal pMac,
                                   tDot11fIEWiderBWChanSwitchAnn *pDot11f,
                                   tpPESession psessionEntry);
#endif
