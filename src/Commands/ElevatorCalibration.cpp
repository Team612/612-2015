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
	time->Reset();
	time->Start();
	printf("Cal Initialize()\n");
}

// Called repeatedly when this Command is scheduled to run
void ElevatorCalibration::Execute()
{
	//printf("Cal Phase 0\n");
	nowTime = time->Get();
	if(nowTime < 5.0)
	{
		printf("Cal Phase 1\n");
		elevator->move(1.0f);
	}
	else if(nowTime < 6.0)
	{
		printf("Cal Phase 2\n");
		elevator->stop();
		if(!stage1)
		{
			elevator->ResetSensors();
			stage1 = true;
		}
		valVectorBottom->push_back(elevator->getElevatorSensorHeight()+prefs->GetFloat("ELEV_OFFSET"));

	}
	else if(nowTime < 20.0)
	{
		printf("Cal Phase 3\n");
		elevator->move(-1.0f);
		if(bottomSum == 0)
		{
			for(std::vector<float>::iterator it = valVectorBottom->begin(); it != valVectorBottom->end(); ++it)
			{
				printf("iter=%f\n", *it);
				bottomSum += *it;
				printf("bottomSum=%f\n", bottomSum);
			}
			bottomSum /= valVectorBottom->size();
			prefs->PutFloat("ELEV_OFFSET", bottomSum);
		}
	}
	else
	{
		printf("Cal Phase 4\n");
		elevator->stop();
		if(elevator->getElevatorSensorHeight()<elevator->getElevatorHeight()-ELEV_CALIBRATION_TOLERANCE)
		{
			printf("Cal Phase 5\n");
			prefs->PutInt("ELEV_CALIBRATION", prefs->GetInt("ELEV_CALIBRATION")+1);
		}
		else if(elevator->getElevatorSensorHeight()>elevator->getElevatorHeight()+ELEV_CALIBRATION_TOLERANCE)
		{
			printf("Cal Phase 6\n");//FACK, NEED TO HARDCODE THIS BECAUSE OF US NOT WORKING.
			prefs->PutInt("ELEV_CALIBRATION", prefs->GetInt("ELEV_CALIBRATION")-1);
		}
		else
		{
			printf("Cal Phase 7\n");
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
	printf("Cal Phase 8\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCalibration::Interrupted()
{

}
