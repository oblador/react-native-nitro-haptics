package com.margelo.nitro.haptics

import android.content.Context
import android.os.Build
import android.os.VibrationEffect
import android.os.Vibrator
import android.os.VibratorManager
import android.os.Handler
import android.os.Looper
import android.util.Log
import androidx.annotation.Keep
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.NitroModules
import com.margelo.nitro.haptics.HapticsVibrationType
import com.margelo.nitro.haptics.ImpactFeedbackStyle
import com.margelo.nitro.haptics.NotificationFeedbackType

class HybridHaptics: HybridHapticsSpec() {
  private val TAG = "Haptics"

  private val context: Context
    get() = NitroModules.applicationContext ?: throw Error("Lost applicationContext")

  private val vibrator: Vibrator
    get() = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
      (context.getSystemService(Context.VIBRATOR_MANAGER_SERVICE) as VibratorManager).defaultVibrator
    } else {
      @Suppress("DEPRECATION")
      context.getSystemService(Context.VIBRATOR_SERVICE) as Vibrator
    }

  private val impactTypes = mapOf(
    ImpactFeedbackStyle.LIGHT to HapticsVibrationType(
      longArrayOf(0, 50),
      intArrayOf(0, 30),
      longArrayOf(0, 20)
    ),
    ImpactFeedbackStyle.SOFT to HapticsVibrationType(
      longArrayOf(0, 50),
      intArrayOf(0, 30),
      longArrayOf(0, 20)
    ),
    ImpactFeedbackStyle.MEDIUM to HapticsVibrationType(
      longArrayOf(0, 43),
      intArrayOf(0, 50),
      longArrayOf(0, 43)
    ),
    ImpactFeedbackStyle.RIGID to HapticsVibrationType(
      longArrayOf(0, 43),
      intArrayOf(0, 50),
      longArrayOf(0, 43)
    ),
    ImpactFeedbackStyle.HEAVY to HapticsVibrationType(
      longArrayOf(0, 60),
      intArrayOf(0, 70),
      longArrayOf(0, 61)
    )
  )

  private val notificationTypes = mapOf(
    NotificationFeedbackType.SUCCESS to HapticsVibrationType(
      longArrayOf(0, 40, 100, 40),
      intArrayOf(0, 50, 0, 60),
      longArrayOf(0, 40, 100, 40)
    ),
    NotificationFeedbackType.WARNING to HapticsVibrationType(
      longArrayOf(0, 40, 120, 60),
      intArrayOf(0, 40, 0, 60),
      longArrayOf(0, 40, 120, 60)
    ),
    NotificationFeedbackType.ERROR to HapticsVibrationType(
      longArrayOf(0, 60, 100, 40, 80, 50),
      intArrayOf(0, 50, 0, 40, 0, 50),
      longArrayOf(0, 60, 100, 40, 80, 50)
    )
  )

  private val selectionType = HapticsVibrationType(
    timings = longArrayOf(0, 50),
    amplitudes = intArrayOf(0, 30),
    oldSDKPattern = longArrayOf(0, 70)
  )
  
  @DoNotStrip
  @Keep
  override fun impact(style: ImpactFeedbackStyle): Unit {
    val vibrationType: HapticsVibrationType = impactTypes.getOrElse(style) {
      throw Error("'style' must be one of ['light', 'medium', 'heavy', 'rigid', 'soft']. Obtained $style'.")
    }
    vibrate(vibrationType)
  }

  @DoNotStrip
  @Keep
  override fun notification(type: NotificationFeedbackType): Unit {
    val vibrationType: HapticsVibrationType = notificationTypes.getOrElse(type) {
      throw Error("'type' must be one of ['success', 'warning', 'error']. Obtained $type'.")
    }
    vibrate(vibrationType)
  }
  
  @DoNotStrip
  @Keep
  override fun selection(): Unit {
    vibrate(selectionType)
  }

  override val memorySize: Long
    get() = 0L

  private fun vibrate(type: HapticsVibrationType) {
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
      vibrator.vibrate(VibrationEffect.createWaveform(type.timings, type.amplitudes, -1))
    } else {
      @Suppress("DEPRECATION")
      vibrator.vibrate(type.oldSDKPattern, -1)
    }
  }
}