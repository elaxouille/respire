import org.openkinect.*;
import org.openkinect.processing.*;

Kinect kinect;

// Taille de l'image captée par la kinect
int w = 640;
int h = 480;

// On regarde tout les X pixels afin de réduire le calcul
int skippy = 4;

int profondeur[][];
int[][] profInitiale;

public int[][] depthMatrix() { // Génération de la matrice de profondeur
	int[] depth = kinect.getRawDepth();

	if (depth != null) {
		for (int x=0; x<w; x+=skippy) {
			for (int y=0; y<h; y+=skippy) {
				int offset = x + y*w; // Calcul du pixel à enregistrer
			
				profondeur[x][y] = depth[offset];
			}
		}
	}
	
	return profondeur;
}

public void setup() { // Initialisation
	kinect = new Kinect(this);
	kinect.start();
	kinect.enableDepth(true);
	kinect.processDepthImage(false);
}

public void draw() {
	
}

public void stop() {
	kinect.quit();
	super.stop();
}
