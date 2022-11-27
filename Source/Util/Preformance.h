/*
  ==============================================================================

    Preformance.h
    Created: 26 Nov 2022 5:07:39pm
    Author:  DarKeN

  ==============================================================================
*/

#pragma once
#include <chrono>
#include <array>
struct Preformance
{
    static const int numberOfIterations = 1000;
    int m_CurrentRun = 0;
    std::array<double, numberOfIterations> m_Timings;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_CaptureTimeStart;
    Preformance()
    {
        for (int i = 0; i <= numberOfIterations; i++)
        {
            m_Timings[i] = 0;
        }
    }

    void StartCapture()
    {
        m_CaptureTimeStart = std::chrono::high_resolution_clock::now();
    }

    void StopCapure()
    {
        if (!Isdone())
        {
            std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
            auto startTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_CaptureTimeStart).time_since_epoch().count();
            auto endTime = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();
            auto duration = endTime - startTime;
            m_Timings[m_CurrentRun] = duration * 0.001;
            m_CurrentRun++;
        }
    }

    double GetAverageRunTime()
    {
        if (Isdone())
        {
            double sum = 0;

            for (int i = 0; i <= numberOfIterations; i++)
            {
                sum += m_Timings[i];
            }
            return sum / numberOfIterations;
        }
        return 0.0;
    }

    bool Isdone() { return m_CurrentRun >= numberOfIterations ? true : false; }
};