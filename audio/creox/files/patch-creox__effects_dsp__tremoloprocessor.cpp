--- creox/effects_dsp/tremoloprocessor.cpp.orig	2011-06-22 06:27:40.000000000 +0900
+++ creox/effects_dsp/tremoloprocessor.cpp	2013-02-18 21:04:20.000000000 +0900
@@ -182,8 +182,8 @@
 		register const float inputSample = *(inputBuffer++) * m_inputGain_f;
 #ifdef FP_FAST_FMAF
 		*(outputBuffer++) = (inputSample * m_dry_f)
-						  + (inputSample * m_wet_f * std::fmaf(amplitudeModulation,
-															   m_modulationMulti, m_modulationShift);
+						  + (inputSample * m_wet_f * fmaf(amplitudeModulation,
+															   m_modulationMulti, m_modulationShift));
 #else
 		*(outputBuffer++) = (inputSample * m_dry_f)
 						  + (inputSample * m_wet_f * ((amplitudeModulation * m_modulationMulti)
