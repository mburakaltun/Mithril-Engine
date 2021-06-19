#include "MithrilEngine.h"
#include <iostream>
#include <string>

namespace Mithril
{
	class Application : MithrilEngine
	{
	public:
		Application() : MithrilEngine("WindowTest", 1920, 1080)
		{

		}

		~Application()
		{
			std::cout << "Destroyed the application" << std::endl;
		}

	protected:
		void Start() override
		{
			InsertDebugLayer();

			object1.AddMeshComponent(MithrilModelLoader::loadWavefrontOBJFile("../Opengl/resources/teapot.obj"));
			object1.SetPosition({0.0f, 0.0f, 0.0f});
			object1.Scale(0.3f);

			object2.AddMeshComponent(MithrilModelLoader::loadDefaultTexturedCube());
			object2.SetPosition({ 0.0f, -1.0f, 0.0f });
			object2.SetScale({ 12.0f, 0.5f, 12.0f });

			/*
			pointLight1.AddPointLightComponent();
			pointLight1.SetPointLightColor(vec3(0.3f, 0.3f, 1.0f));
			pointLight1.SetPosition({0.0f, 0.0f, -2.0f});

			pointLight2.AddPointLightComponent();
			pointLight2.SetPointLightColor(vec3(1.0f, 0.3f, 0.3f));
			pointLight2.SetPosition({ 2.0f, 0.0f, 0.0f });
			*/

			SetDirLightDirection({0.45f, 0.5f, 0.3f});
			SetDirLightColor({1.0f, 1.0f, 1.0f });

			SetActiveCameraPosition({0.0f, 0.0f, 6.0f});
			setActiveCameraHeading(-90.0f, 0.0f);

			LockCursor();
		}

		void Run() override
		{
			static float movementSensitivity = 0.1f;
			static vec3 currentCamPos(0.0f, 0.0f, 3.0f);
			static float currentCamYaw = -90.0f;
			static float currentCamPitch = 0.0f;
			static vec3 cameraFront;
			static vec3 cameraRight;
			static vec3 cameraUp;
			const static vec3 worldUp(0.0f, 1.0f, 0.0f);

			cameraFront.x = cos(Math::radians(currentCamYaw)) * cos(Math::radians(currentCamPitch));
			cameraFront.y = sin(Math::radians(currentCamPitch));
			cameraFront.z = sin(Math::radians(currentCamYaw)) * cos(Math::radians(currentCamPitch));

			cameraRight = Math::normalize(Math::cross(cameraFront, worldUp));
			cameraUp = Math::normalize(Math::cross(cameraRight, cameraFront));
			
			//Handling movement keys

			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_W))
			{
				currentCamPos += cameraFront * movementSensitivity;
			}
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_S))
			{
				currentCamPos -= cameraFront * movementSensitivity;
			}
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_D))
			{
				currentCamPos += cameraRight * movementSensitivity;
			}
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_A))
			{
				currentCamPos -= cameraRight * movementSensitivity;
			}
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_SPACE))
			{
				currentCamPos += cameraUp * movementSensitivity;
			}
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_LEFT_CONTROL))
			{
				currentCamPos -= cameraUp * movementSensitivity;
			}

			//Cursors
			if (IsKeyPressed(KEYCODES::MITHRIL_KEY_ESCAPE))
			{
				UnlockCursor();
			}

			//handling yaw-pitch
			currentCamPitch -= Input::GetYOffset() * 0.15f;
			currentCamYaw += Input::GetXOffset() * 0.15f;

			if (currentCamPitch > 89.0f) currentCamPitch = 89.0f;
			if (currentCamPitch < -89.0f) currentCamPitch = -89.0f;

			SetActiveCameraPosition(currentCamPos);
			setActiveCameraHeading(currentCamYaw, currentCamPitch);
		}
	private:
		Entity object1, object2, pointLight1, pointLight2;
	};
}

int main()
{
	Mithril::MithrilEngine* app = (Mithril::MithrilEngine*) new Mithril::Application();
	app->Execute();
	delete app;
}