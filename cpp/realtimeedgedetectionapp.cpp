#include "jni.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <string>

using namespace cv;

extern "C" {
JNIEXPORT void JNICALL Java_com_wintershade_RealTimeEdgeDetectionApp_MainActivity_FindFeatures(JNIEnv * jniEnv, jobject, jlong addrGray, jlong addrRGBA)
{
    Mat* mGray = (Mat*)addrGray;
    Mat* mRGBA = (Mat*)addrRGBA;

    // Create output edge map (single-channel, same size as input gray)
    Mat edges;
    // Canny parameters: lowThreshold=50, highThreshold=150
    // Use 3x3 Gaussian for smoothing (default aperture size)
    Canny(*mGray, edges, 50, 150, 3);

    // Convert edges (CV_8UC1) to RGBA (CV_8UC4) for display: replicate gray channel to R/G/B, alpha=255
    cvtColor(edges, *mRGBA, COLOR_GRAY2RGBA);
}
}