
#include "../Include/CAppGrid.h"



CAppGrid::CAppGrid(): m_CamPosition (-5.0f,-5.0f,-7.0f)
{
	cout << "Constructor: CAppGrid()" << endl;

   m_World = new CWorld();
}


/* */
CAppGrid::CAppGrid(int window_width, int window_height) : CApp(window_width, window_height), m_CamPosition(-5.0f,-5.0f,-5.0f)
{
	cout << "Constructor: CAppGrid(int window_width, int window_height)" << endl;

		m_World = new CWorld();
}

CAppGrid::~CAppGrid()
{
	cout << "Destructor: ~CAppGrid()" << endl;
}

bool CAppGrid::initializeMenu()
{
	cout << "CAppGrid::initializeMenu()" << endl;

	return true;
}

void CAppGrid::initialize()
{
	// initialize del world
}

void CAppGrid::update(double deltaTime)
{
	m_currentDeltaTime = deltaTime;
}

void CAppGrid::run()
{
	initialize();

	// Check if CGameWindow object and window library been initialized
	if (canRun())
	{
		// Create the Window 
		if (getGameWindow()->create(CAPPHEXGRID_WINDOW_TITLE))
		{
			// Set initial clear screen color
			getOpenGLRenderer()->setClearScreenColor(0.15f, 0.75f, 0.75f);
			// Initialize window width/height in the renderer
			getOpenGLRenderer()->setWindowWidth(getGameWindow()->getWidth());
			getOpenGLRenderer()->setWindowHeight(getGameWindow()->getHeight());

			//getOpenGLRenderer()->initializeTestObjects();
			// Create our menu (add all menu items)

			m_World->initialize(getOpenGLRenderer());
			if (!initializeMenu())
			{
				return;
			}

			// Enter main loop
			cout << "Entering Main loop" << endl;
			getGameWindow()->mainLoop(this);
		}
	}
}

void CAppGrid::render()
{
	CGameMenu *menu = getMenu();
	CVector3 objPos2;
	objPos2.setValues(m_CamPosition.getX() + 2.5f, m_CamPosition.getY(), m_CamPosition.getZ());



	// If menu is active, render menu
	if (menu != NULL && menu->isInitialized() && menu->isActive())
	{
		menu->render(getOpenGLRenderer());
	}
	else // Otherwise, render active object if loaded (or test cube if no object is loaded)
	{
		// White 
		float color[3] = { 105.0f, 105.0f, 105.0f };
		/*
		MathHelper::Matrix4 modelMatrix = MathHelper::ModelMatrix((float)0, m_CamPosition);

		CVector3 pos2 = m_CamPosition;
		pos2 += CVector3(3.0f, 10.0f, 0.0f);
		MathHelper::Matrix4 modelMatrix2 = MathHelper::ModelMatrix((float)0, pos2);

		*/


			m_World->render(m_CamPosition);

	
		// render del world

	}
}
void CAppGrid::executeMenuAction()

{
	if (getMenu() != NULL)
	{
	}
}

void CAppGrid::onF3(int mods)
{
	// Check BITWISE AND to detect shift/alt/ctrl
	if (mods & KEY_MOD_SHIFT)
	{
		moveCamera(-1.0f);
	}
	else
	{
		moveCamera(1.0f);
	}
}

void CAppGrid::onMouseMove(float deltaX, float deltaY)
{
	if (deltaX < 100.0f && deltaY < 100.0f)
	{

		float moveX = -deltaX * DEFAULT_CAMERA_MOVE_SPEED;
		float moveZ = -deltaY * DEFAULT_CAMERA_MOVE_SPEED;

		float currPos[3];
		m_CamPosition.getValues(currPos);
		currPos[0] += moveX;
		currPos[2] += moveZ;
		m_CamPosition.setValues(currPos);
	}

}

void CAppGrid::moveCamera(float direction)
{
	if (getOpenGLRenderer() != NULL)
	{
		getOpenGLRenderer()->moveCamera(direction);
	}
}