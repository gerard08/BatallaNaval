#include <cstdlib>
#include <cassert>

#ifndef __NOT_GRAPHICS
#include "image_png.h"
#endif
#include "video.h"
#include "sprites.h"
#include "error.h"


Sprite::Sprite(){}

Sprite::Sprite(const char *ruta)
{
#ifndef __NOT_GRAPHICS
  //Inicializamos
  animacion = NULL;

  // Por defecto cada frame dura... Un frame :-)
  velocidad_animacion = 1.0f ;
  setScale(1.0f) ;

  if(ruta != SPRITE_WILL_BE_ANIMATED)
  {
    // Si no es NULL, creamos un frame para contener la imagen que toque
    frame_actual = CreateFrame(ruta) ;
  } // Si recibimos un NULL, queremos un sprite "vacio" para ponerle luego animaciones
#endif
}

Sprite::~Sprite()
{
#ifdef __NOT_GRAPHICS		//això és ifndef
  if(animacion == NULL)
  {
    // Si el sprite no tiene animación es que solo tiene su frame actual
    // Si el frame tiene un handle de textura pedimos al hardware que se olvide de la imagen y
    // libere la memoria y los handles que haya podido alojar
    if(frame_actual->texture) SDL_DestroyTexture(frame_actual->texture);

    // Si el frame tiene una surface de SDL la liberamos
    if(frame_actual->surface) SDL_FreeSurface(frame_actual->surface);

    //Limpiamos el resto
    delete frame_actual;
  } // Si el sprite tiene animación no hacemos nada, las animaciones se tienen que liberar a mano
  IMG_Quit();
#endif
}

struct T_ANIMATION *Sprite::CreateAnimation(struct T_DESCRIPCION_ANIMACION *descripcion_anim)
{
#ifndef __NOT_GRAPHICS
  assert(descripcion_anim) ;

  T_ANIMATION *anim = new T_ANIMATION();

  anim->frames = new Frame*() ;
  anim->num_frames = descripcion_anim->num_frames ;
  anim->tiene_loop = descripcion_anim->modo_loop ;

  T_DESCRIPCION_FRAME_ANIMACION *descripcion_frame;
  for(int var_frame = 0; var_frame < descripcion_anim->num_frames; var_frame++) {

    descripcion_frame = descripcion_anim->descripcion_frames[var_frame] ;

    anim->frames[var_frame] = CreateFrame(descripcion_frame->ruta) ;

    anim->frames[var_frame]->duracion = descripcion_frame->duracion ;
    anim->frames[var_frame]->hx       = descripcion_frame->hx ;
    anim->frames[var_frame]->hy       = descripcion_frame->hy ;
  }
  return anim ;
#else
	return nullptr;
#endif
}

void Sprite::SetAnimation(struct T_ANIMATION *anim, bool OverWrite)
{
#ifndef __NOT_GRAPHICS
  assert(anim);

  //No podemos permitir que si el sprite esta gestionando un frame por su cuenta se pierda en el limbo.
  //Si la animacion es NULL el frame actual no puede serlo
  if(animacion == NULL)
  {
    assert( frame_actual == NULL);
  }

  if(OverWrite || anim != animacion)
  {
      animacion = anim ;
      frame_actual = anim->frames[0] ;
      num_frame_actual = 0 ;
      posicion_animacion = 0 ;
      animacion_completada = false ;
    }
#endif
}

void Sprite::ReleaseFrame(Frame *frame) const
{
#ifndef __NOT_GRAPHICS
  // Si el frame tiene un handle de textura pedimos al hardware que se olvide de la imagen y
  // libere la memoria y los handles que haya podido alojar
  if(frame->texture) SDL_DestroyTexture(frame->texture) ;

  // Si el frame tiene una surface de SDL la liberamos
  if(frame->surface) SDL_FreeSurface(frame->surface) ;
#endif
}



void Sprite::ReleaseAnimation(struct T_ANIMATION *anim)
{
#ifndef __NOT_GRAPHICS
  assert(anim) ;

  for(int var_frame = 0; var_frame < anim->num_frames; var_frame++)
  {
    ReleaseFrame(anim->frames[var_frame]) ;
  }

  delete anim;
#endif
}

void Sprite::SetAnimationSpeed(float speed)
{
#ifndef __NOT_GRAPHICS
  velocidad_animacion = speed ;
#endif
}

void Sprite::SetFrame(int num_frame)
{
#ifndef __NOT_GRAPHICS
  if(num_frame < 0) num_frame = 0 ;
  if(num_frame >= animacion->num_frames) num_frame = animacion->num_frames - 1 ;

  num_frame_actual = num_frame ;
   posicion_animacion = 0 ;
#endif
}

// Escala el tamaño horizontal del sprite por el factor indicado
void Sprite::SetScaleX(float new_scalex)
{
#ifndef __NOT_GRAPHICS
  if(new_scalex < 0.0f) new_scalex = 0.0f ;
  scalex = new_scalex ;
#endif
}

// Escala el tamaño vertical del sprite por el factor indicado
void Sprite::SetScaleY(float new_scaley)
{
#ifndef __NOT_GRAPHICS
  if(new_scaley < 0.0f) new_scaley = 0.0f ;
  scaley = new_scaley ;
#endif
}

// Escala el tamaño del sprite por el factor indicado
void Sprite::setScale(float scale)
{
#ifndef __NOT_GRAPHICS
  if(scale < 0.0f) scale = 0.0f ;

  scalex = scale ;
  scaley = scale ;
#endif
}

// Dibuja un sprite en las coordenadas especificadas
void Sprite::draw(int x, int y)
{
#ifndef __NOT_GRAPHICS
  //Nos aseguramos de que el vídeo está en marcha
  assert(g_Video.renderer) ;
  //Variable para que el cóigo quede más corto y legible
  Frame* frame =  frame_actual;
  // Si el sprite no tiene un frame que dibujar nos marchamos
  if(frame == NULL) return ;
  if(frame->surface == NULL) return ;


  // Nos aseguramos de que el sprite tiene textura
  assert(frame->texture) ;

  // La SDL necesita que le especifiquemos un par de rectángulos en su formato para poder dibujar
  SDL_Rect srcrect ;
  SDL_Rect dstrect ;

  // Posición de la esquina superior izquierda
  srcrect.x = 0 ;
  srcrect.y = 0 ;

  // Número de píxels a leer
  srcrect.w = frame->tamx;
  srcrect.h = frame->tamy ;

  // Posición de la esquina superior izquierda al dibujar
  dstrect.x = x - static_cast<int>(frame->hx * scalex) ;
  dstrect.y = y - static_cast<int>(frame->hy * scaley) ;

  // Tamáño visible al dibujar
  dstrect.w = static_cast<int>(frame->tamx * scalex) ;
  dstrect.h = static_cast<int>(frame->tamy * scaley) ;

  SDL_RenderCopy(g_Video.renderer, frame->texture, &srcrect, &dstrect) ;
#endif
}

// Crea un sprite, vacío si ruta == SPRITE_WILL_BE_ANIMATED, o con un frame conteniendo el .png
// situado en la ruta
void Sprite::create(const char *ruta)
{
#ifndef __NOT_GRAPHICS
  //Inicializamos
  animacion = NULL;

  // Por defecto cada frame dura... Un frame :-)
  velocidad_animacion = 1.0f ;
  setScale(1.0f) ;

  if(ruta != SPRITE_WILL_BE_ANIMATED)
  {
    // Si no es NULL, creamos un frame para contener la imagen que toque
    frame_actual = CreateFrame(ruta) ;
  } // Si recibimos un NULL, queremos un sprite "vacio" para ponerle luego animaciones
#endif
}

int Sprite::getScaleY() const
{
#ifndef __NOT_GRAPHICS
  return frame_actual->tamy;
#else
	return 0;
#endif
}

int Sprite::getScaleX() const
{
#ifndef __NOT_GRAPHICS
  return frame_actual->tamx;
#else
	return 0;
#endif
}

void Sprite::Tick()
{
#ifndef __NOT_GRAPHICS
  T_ANIMATION *new_animacion;

  new_animacion = animacion;
  if(animacion == NULL) return ;

  posicion_animacion += velocidad_animacion ;

  while( posicion_animacion >= new_animacion->frames[num_frame_actual]->duracion)
  {
    posicion_animacion -= new_animacion->frames[num_frame_actual]->duracion ;
    num_frame_actual++ ;

    if(num_frame_actual >= new_animacion->num_frames)
    {
      animacion_completada = true ;

      if(new_animacion->tiene_loop) num_frame_actual = 0 ;
      else num_frame_actual = new_animacion->num_frames - 1 ;
    }
  }
   frame_actual = new_animacion->frames[num_frame_actual] ;
#endif
}

Frame* Sprite::CreateFrame(const char *ruta)
{
#ifndef __NOT_GRAPHICS
  assert(ruta) ;

  Frame* frame = new Frame();

  //Lee el tamaño de X e Y
  read_png_file(ruta, &frame->tamx, &frame->tamy) ;

  frame->surface = IMG_Load(ruta);
  if(frame->surface == NULL)
    throw custom_error("[Sprite::CreateFrame] No se ha podido cargar la imágen");

  // Creamos el handle de textura de hardware
  frame->texture = SDL_CreateTextureFromSurface(g_Video.renderer, frame->surface) ;

  // Indicamos al hardware de que este sprite va a necesitar c?culos de alpha blending (para que no se vea el rect?gulo donde no hay dibujo)
  SDL_SetTextureBlendMode(frame->texture, SDL_BLENDMODE_BLEND);

  return frame;
#else
	return nullptr;
#endif
}
