#ifndef _CAMERA_HPP_
# define _CAMERA_HPP_

#include "Maths/Vector.hpp"
#include "Maths/Matrix.hpp"

namespace te
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void rotateY(float yaw);
		void rotateX(float roll);
		void rotateZ(float pitch);

		void setYaw(float newYaw);
		void setPitch(float newPitch);

		/* Getters */
		const float getYaw() const;
		const float getPitch() const;
		const float getRoll() const;
		const float getHFov() const;
		const float getVFov() const;
		const sml::vec3& getPos() const;
		const sml::vec3& getFrontVec() const;
		const sml::vec3& getRightVec() const;

		/* Movement */
		void moveForward(float deltaTime);
		void moveBackward(float deltaTime);
		void moveLeft(float deltaTime);
		void moveRight(float deltaTime);

		void updateView();

	public:
		float moveSpeed{};
		float rotationSpeed{};
		sml::vec3 pos{};
		sml::mat4 view{};
		bool bIsDirty = true;
		
	private:
		sml::vec3 front{};
		sml::vec3 right{};
		sml::vec3 up{};

		float yaw{};
		float pitch{};
		float roll{};

		float vfov{};
		float hfov{};
	};

}

#endif