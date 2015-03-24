#include "ElevatorCalibration.h"

ElevatorCalibration::ElevatorCalibration()
{
	Requires(elevator);
	time = new Timer();
	nowTime = 0.0;
	valVectorBottom = new std::vector<float>;
	valVectorTop = new std::vector<float>;
	prefs = Preferences::GetInstance();
	bottomSum = 0;
	topSum = 0;
	ELEV_CALIBRATION_TOLERANCE = 0.5f;
	isFinished = false;
	stage1 = false;
}

// Called just before this Command runs the first time
void ElevatorCalibration::Initialize()
{
	time->Start();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorCalibration::Execute()
{
	nowTime = time->Get();
	if(nowTime < 2.0)
	{
		elevator->move(-0.8f);
	}
	else if(nowTime < 4.0)
	{
		elevator->stop();
		if(!stage1)
		{
			elevator->ResetSensors();
			stage1 = true;
		}
		valVectorBottom->push_back(elevator->getElevatorSensorHeight()+prefs->GetFloat("ELEV_OFFSET"));
	}
	else if(nowTime < 6.0)
	{
		if(bottomSum == 0)
		{
			for(std::vector<float>::iterator it = valVectorBottom->begin(); it != valVectorBottom->end(); ++it)
			{
				bottomSum += *it;
			}
			bottomSum = (bottomSum/valVectorBottom->size());
			prefs->PutFloat("ELEV_OFFSET", bottomSum);
		}
		elevator->move(0.8f);
	}
	else
	{
		elevator->stop();
		if(elevator->getElevatorSensorHeight()<elevator->getElevatorHeight()-ELEV_CALIBRATION_TOLERANCE)
		{
			prefs->PutInt("ELEV_CALIBRATION", prefs->GetInt("ELEV_CALIBRATION")+1);
		}
		else if(elevator->getElevatorSensorHeight()>elevator->getElevatorHeight()+ELEV_CALIBRATION_TOLERANCE)
		{
			prefs->PutInt("ELEV_CALIBRATION", prefs->GetInt("ELEV_CALIBRATION")-1);
		}
		else
		{
			isFinished = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCalibration::IsFinished()
{
	return isFinished;
}

// Called once after isFinished returns true
void ElevatorCalibration::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCalibration::Interrupted()
{

}
