//   CUDA_MLS Framework
//
//   Copyright 2017-2018 Evangelos D. Katsavrias, Luxembourg
//
//   This file is part of the CUDA_MLS Framework.
//
//   CUDA_MLS Framework is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 3 as published by
//   the Free Software Foundation.
//
//   CUDA_MLS Framework is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with CUDA_MLS Framework.  If not, see <https://www.gnu.org/licenses/>.
//
//   Contact Info:
//   Evangelos D. Katsavrias
//   email/skype: vageng@gmail.com
// -----------------------------------------------------------------------

#include <QApplication>
#include <QGuiApplication>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>

class testScene : public QObject
{

public:
    explicit testScene(Qt3DCore::QEntity *rootEntity);
    ~testScene() {}

public slots:
void enableCuboid(bool enabled)
{
    m_cuboidEntity->setEnabled(enabled);
}

void enablePlane(bool enabled)
{
    m_planeEntity->setEnabled(enabled);
}


private:
    Qt3DCore::QEntity*	m_rootEntity;
    Qt3DCore::QEntity*	m_cuboidEntity;
    Qt3DCore::QEntity*	m_planeEntity;
    Qt3DCore::QEntity*	m_sphereEntity;
    Qt3DCore::QEntity*	m_torusEntity;

};


testScene::testScene(Qt3DCore::QEntity *rootEntity): m_rootEntity(rootEntity)
{
	// Material
	Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(m_rootEntity);
	
	// Torus
	Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
	torusMesh->setRadius(5);
	torusMesh->setMinorRadius(1);
	torusMesh->setRings(100);
	torusMesh->setSlices(20);

	Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
	torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
	torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

	Qt3DCore::QEntity *m_torusEntity = new Qt3DCore::QEntity(m_rootEntity);
	m_torusEntity->addComponent(torusMesh);
	m_torusEntity->addComponent(torusTransform);
	m_torusEntity->addComponent(material);

	// Sphere
	Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
	sphereMesh->setRadius(3);

	Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;
	sphereTransform->setScale3D( QVector3D(1, 1, 1) );

	Qt3DCore::QEntity *m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
	m_sphereEntity->addComponent(sphereMesh);
	m_sphereEntity->addComponent(sphereTransform);
	m_sphereEntity->addComponent(material);

}


